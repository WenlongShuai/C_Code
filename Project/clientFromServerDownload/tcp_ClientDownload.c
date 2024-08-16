#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket fail:");
		return -1;
	}

	struct sockaddr_in mySockAddr;
	mySockAddr.sin_family = AF_INET;
	mySockAddr.sin_port = htons(1111);
	mySockAddr.sin_addr.s_addr = inet_addr("192.168.143.128");

	struct sockaddr_in serverSockAddr;
	serverSockAddr.sin_family = AF_INET;
	serverSockAddr.sin_port = htons(1314);
	serverSockAddr.sin_addr.s_addr = inet_addr("192.168.143.128");

	int res = bind(sockfd, (struct sockaddr*)&mySockAddr, sizeof(mySockAddr));
	if(res < 0)
	{
		perror("bind fail:");
		return -1;
	}

	res = connect(sockfd, (struct sockaddr*)&serverSockAddr, sizeof(serverSockAddr));
	if(res < 0)
	{
		perror("connect fail:");
		return -1;
	}

	char recvBuf[50] = {0};
	char flag[10] = {0};
	char input[200] = {0};
	char *file[2] = {NULL, NULL};

	while(1)
	{
		char *str = NULL;
		unsigned char i = 0;
		printf("请输入要下载的文件名以及保存文件的路经：\n");
		fgets(input, 200, stdin);
		while(!strcmp(input, "\n"))
		{
			printf("输入参数不能为空,请重新输入：\n");
			fgets(input, 200, stdin);
		}
		
		if(!strcmp(input, "quit\n"))
		{
			write(sockfd, "quit\n",6);
			break;
		}

		input[strlen(input)-1] = 0; 

		for(str = strtok(input, " "),i=0; str !=  NULL && i < 2; str = strtok(NULL, " "),i++)
		{
			file[i] = str;
		}

		char * p = strchr(file[0], '/');
		unsigned char pos = 0;
		while(p != NULL)
		{
			pos = p-file[0];
			p = strchr(p+1, '/');
		}
		
		char fileTemp[20] = {0};
		
		if(pos == 0)
		{
			strncpy(fileTemp, file[0], 20);
		}
		else
		{
			strncpy(fileTemp, file[0]+pos+1, 20);
		}

		if(file[1] == NULL)
		{
			file[1] = fileTemp;
		}
		else
		{
			DIR *dir = opendir(file[1]);
			if(dir != NULL)
			{
				strncat(file[1], fileTemp, strlen(fileTemp));
			}
			closedir(dir);
		}

		printf("download file: %s\n", file[0]);
		printf("save file: %s\n", file[1]);

		write(sockfd, file[0], strlen(file[0]));
		
		read(sockfd, flag, 8);
		if(!strcmp(flag, "flagOk\n"))
		{
			printf("等待下载....\n");
			FILE *f = fopen(file[1], "w+");
			if(f == NULL)
			{
				perror("fopen fail:");
				return -1;
			}
	
			while(1)
			{
				int num = read(sockfd, recvBuf, sizeof(recvBuf));

				if(num < sizeof(recvBuf))
				{
					fwrite(recvBuf, 1, num, f);
					memset(recvBuf, 0, sizeof(recvBuf));
					write(sockfd, "writeOk\n", 9);
					read(sockfd, recvBuf, 8);
					if(!strcmp(recvBuf, "recvOk\n"))
					{
						break;
					}
				}

				fwrite(recvBuf, 1, num, f);
				memset(recvBuf, 0, sizeof(recvBuf));
			}

			fclose(f);
			printf("下载完成\n");
			write(sockfd, "downOk\n", 8);
		}
		else if(!strcmp(flag, "flagNo\n"))
		{
			printf("没有 %s 文件\n", file[0]);
			printf("重新输入文件和路径\n");
		}

		memset(recvBuf, 0, sizeof(recvBuf));
		memset(input, 0 ,sizeof(input));
		file[0] = NULL;
		file[1] = NULL;
	}

	close(sockfd);


	return 0;
}
