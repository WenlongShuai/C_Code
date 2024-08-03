#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sqlite3.h>
void do_register(int serverfd);
void do_login(int serverfd);
int call(void *arg,int f_num,char **f_val,char **f_name);
void do_query(int serverfd);

typedef struct
{
	char type;
	char name[100];
	char data[256];
}MSG;
MSG msg;
int main()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket fail");
		return -1;
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9999);
	serveraddr.sin_addr.s_addr = inet_addr("192.168.1.110");

	int num = bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(num < 0)
	{
		perror("server bind fail");
		return -1;
	}

	listen(sockfd,10);


	while(1)
	{
		int serverfd = accept(sockfd,NULL,NULL);
		if(serverfd < 0)
		{
			return -1;
		}
		pid_t pid = fork();
		if(pid == 0)
		{
			while(1)
			{
				read(serverfd,&msg,sizeof(msg));
				switch(msg.type)
				{
					case 'R':
						do_register(serverfd);
						break;
					case 'L':
						do_login(serverfd);
						break;
					case 'Q':
						do_query(serverfd);
						break;
				}	
			
			}
		
		}

		else if(pid < 0)
		{
			perror("fork fail");
			return -1;
		}
	}
	return 0;
}

int call(void *arg,int f_num,char **f_val,char **f_name)
{
        int serverfd = *(int *)arg;
        for(int i = 0;i < f_num;i++)
        {
                if( (strcmp(f_val[i],msg.name) == 0) && (strcmp(f_val[i+1],msg.data) == 0) )
                {
                        write(serverfd,"have",5);
                        return 0;
                }
        }
        return 0;
}

void do_register(int serverfd)
{
	sqlite3 *pdb;
	int sqflag = sqlite3_open("./user_manage.db",&pdb);
	if(sqflag < 0)
	{
		return;
	}

	char buff[400] = {0};
	char buff2[500] = {0};
	sprintf(buff,"insert into user values(\"%s\",\"%s\")",msg.name,msg.data);
	sprintf(buff2,"select * from user where name=\"%s\" and passwd=\"%s\"",msg.name,msg.data);
	
	int num = sqlite3_exec(pdb,buff2,call,&serverfd,NULL);//判断是否有
	if(num == 0)
	{
		sqlite3_exec(pdb,buff,NULL,NULL,NULL);//插入
		write(serverfd,"register succeed",17);
	}

	sqlite3_close(pdb);
}

int callback(void *arg,int f_num,char **f_val,char **f_name)
{
	int serverfd = *(int *)arg;
	for(int i = 0;i < f_num;i++)
	{
		if( (strcmp(f_val[i],msg.name) == 0) && (strcmp(f_val[i+1],msg.data) == 0) )
		{
			write(serverfd,"login ok",9);
			return 0;
		}
	}

	return 0;
}
void do_login(int serverfd)
{
	sqlite3 *pdb;
	int sqflag = sqlite3_open("user_manage.db",&pdb);
	if(sqflag < 0)
	{
		return ;
	}

	char buff[500] = {0};
	sprintf(buff,"select * from user where name=\"%s\" and passwd=\"%s\"",msg.name,msg.data);
	int num = sqlite3_exec(pdb,buff,callback,&serverfd,NULL);
	if(num == 0)
	{
		write(serverfd,"username and passwd error",26);
	}

	sqlite3_close(pdb);
}


void do_query(int serverfd)
{
	char data[100] = {0};
	FILE* fp = fopen("./dict.txt","r");
	if(fp < 0)
	{
		perror("fopen fail");
		return;
	}

	int i = 0,j = 0;
	while( fgets(data,100,fp) != NULL )
	{
		while( (data[i] != ' ') && (msg.data[j] != '\0') )
		{
			if( data[i] == msg.data[j] )
			{
				j++;
			}
			i++;
		}

		if(j == strlen(msg.data))
		{
			while( *(data+j) == ' ' )
			{
				j++;
			}
			write(serverfd,(data+j),100);
			return;
		}
		
		i = 0;
		j = 0;
		bzero(data,100);	
	}
	write(serverfd,"not found word",15);
}

