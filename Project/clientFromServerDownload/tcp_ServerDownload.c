#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>         /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>

int downloadFile(int client_fd);

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket fail:");
		return -1;
	}

	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(1314);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.143.128");

	int res = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(res < 0)
	{
		perror("bind fail:");
		return -1;
	}

	listen(sockfd, 5);

	printf("listen ok\n");

	struct sockaddr_in clientAddr;
	socklen_t len;
	int client_fd;
	int pid;

	while(1)
	{
		client_fd = accept(sockfd, (struct sockaddr*)&clientAddr, &len);
		if(client_fd < 0)
		{
			perror("accept fail:");
			return -1;
		}
		
		printf("client %d,  ip : %s,  port : %d\n",client_fd,inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

		pid = fork();
		if(pid == 0)
		{
			//子进程
			char sentBuf[50] = {0};
			char recvBuf[50] = {0};
			int res = 0;

			while(1)
			{
				res = downloadFile(client_fd);
				if(res < 0)
					return -1;
				else if(res == 1)
					break;
			}

			printf("client %d exit\n",client_fd);
			
			close(client_fd);
			exit(0);
		}
	}

	close(sockfd);

	waitpid(-1, NULL, 0);

	return 0;
}


int downloadFile(int client_fd)
{
	unsigned char flag = 0;
	unsigned char pos = 0;
	char path[100] = {0};
	char file[50] = {0};
	char recvBuf[50] = {0};

	read(client_fd, recvBuf, sizeof(recvBuf));

	if(!strcmp(recvBuf, "quit\n"))
	{
		return 1;
	}

	char * p = strchr(recvBuf, '/');
	while(p != NULL)
	{
		pos = p-recvBuf;
		p = strchr(p+1, '/');

	}

	if(pos == 0)
	{
		strncpy(path, "./", 3);
		strncpy(file, recvBuf, 20);
	}
	else
	{
		strncpy(path, recvBuf, pos+1);
		strncpy(file, recvBuf+pos+1, 20);
	}

	printf("path = %s\n",path);
	printf("file = %s\n",file);

	DIR *dir = opendir(path);
	if(dir == NULL)
	{
		perror("opendir fail:");
		return -1;
	}
	struct dirent *dirName;
	errno = 0;

	while(1)
	{
		dirName = readdir(dir);
		if(dirName == NULL)
		{
			if(errno == 0)	
			{
				flag = 0;
				break;
			}
			else
			{
				perror("readdir fail:");
				return -1;
			}
		}
		if(!strcmp(dirName->d_name, file))
		{
			flag = 1;
			break;
		}
	}
	closedir(dir);

	if(flag)
	{
		char cal[10] = {0};
		write(client_fd, "flagOk\n",8);
		printf("找到 %s 文件\n",file);
		char readFile[50] = {0};

		FILE *f = fopen(recvBuf, "r+");
		if(f == NULL)
		{
			perror("fopen fail:");
			return -1;
		}

		while(1)
		{
			int num = fread(readFile, 1, sizeof(readFile), f);
			if(num > 0)
				write(client_fd, readFile, num);
			else
				break;
		}
		fclose(f);

		memset(recvBuf,0 ,sizeof(recvBuf));
		read(client_fd, recvBuf, 9);
		if(!strcmp(recvBuf, "writeOk\n"))
		{
			write(client_fd, "recvOk\n", 8);
		}


		memset(recvBuf,0 ,sizeof(recvBuf));
		read(client_fd, recvBuf, 8);
		if(!strcmp(recvBuf, "downOk\n"))
			printf("客户端下载完成\n");
		else
			printf("客户端未下载完成\n");
	}
	else
	{
		printf("未找到 %s 文件\n",file);
		write(client_fd, "flagNo\n",8);
	}
	
	memset(recvBuf, 0, sizeof(recvBuf));
	
	return 0;
}
