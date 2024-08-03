#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>


void do_register(int sockfd);
int do_login(int sockfd);
void do_query(int sockfd);
int start_print();
int query_print();
void query_word(int sockfd);

typedef struct
{
	char type;
	char name[100];
	char data[256];
}MSG;

int main()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("client sockfd fail");
		return -1;
	}

	struct sockaddr_in clientaddr;
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(6666);
	clientaddr.sin_addr.s_addr = inet_addr("192.168.1.110");

	int num = bind(sockfd,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	if(num < 0)
	{
		perror("client bind fail");
		return -1;
	}
	
	struct sockaddr_in serveraddr;
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(9999);
        serveraddr.sin_addr.s_addr = inet_addr("192.168.1.110");
	
	int num2 = connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(num2 < 0)
	{
		perror("client connect fail");
		return -1;
	}
	
	int choose = 0;
	//通信
	while(1)
	{
		choose = start_print();
		switch(choose)
		{
			case 1:  // register
				do_register(sockfd);
				break;
			case 2:  //login
				if(do_login(sockfd))
				{
					do_query(sockfd);		
				}
				break;
			case 3:
				close(sockfd);
				//exit(0);
				return 0;
		}
	}

	return 0;
}

int start_print()
{
	int choose = 0;
	while(1)
	{
		printf("****************************************\n");
		printf("* 1: register  2: login  3: quit_login *\n");
		printf("****************************************\n");
		printf("please choose:");
		scanf("%d",&choose);
		printf("\n");
		if(choose > 0 && choose < 4)
		{
			break;
		}
		else
		{
			printf("please enter again choose:\n");
		}	
	}
	return choose;
}

int query_print()
{
	int choose = 0;
	while(1)
	{
		printf("***************************************************\n");
		printf("* 1: query_word  2: history_record  3: quit_query *\n");
		printf("***************************************************\n");
		printf("please choose:");
		scanf("%d",&choose);
		printf("\n");
		if(choose > 0 && choose < 4)
		{
			return choose;
		}
		else
		{
			printf("please enter again choose:\n");
		}
	}
}

void do_register(int sockfd)
{
	MSG msg;
	char flag[20] = {0};
	msg.type = 'R';

	printf("please input register username:");
	scanf("%s",msg.name);
	printf("please input register passwd:");
	scanf("%s",msg.data);
	
	write(sockfd,&msg,sizeof(msg));
	
	read(sockfd,flag,20);
	if(strcmp(flag,"have") == 0)
	{
		printf("The account is registered\n");
		printf("\n");
		do_register(sockfd);
	}
	else
	{
		printf("%s\n",flag);
	}

}


int do_login(int sockfd)
{
	MSG msg;
	msg.type = 'L';
	char buff[50] = {0};
	printf("please input login username:");
	scanf("%s",msg.name);
	printf("please input login passwd:");
	scanf("%s",msg.data);

	write(sockfd,&msg,sizeof(msg));

	int num = read(sockfd,buff,50);
	if(num > 0)
	{
		printf("%s\n",buff);
		printf("\n");
	}
	

	if(strcmp(buff,"login ok") == 0)
	{
		return 1;
	}

	return 0;
}

void do_query(int sockfd)
{
	int choose = 0;
	choose = query_print();

	switch(choose)
	{ 
		case 1: //query_word
			query_word(sockfd);
			break;
		case 2: //history_record
			break;
		case 3: //quit_query
			close(sockfd);
			exit(0);
			break;
	}
}

void query_word(int sockfd)
{
	MSG msg;
	printf("please input word:");
	msg.type = 'Q';
	scanf("%s",msg.data);

	write(sockfd,&msg,sizeof(msg));

	char buff[100] = {0};
	int num = read(sockfd,buff,100);
	if(num > 0)
	{
		printf("%s\n",buff);
	}
	do_query(sockfd);
}


/*
void history_record()
{


}*/
