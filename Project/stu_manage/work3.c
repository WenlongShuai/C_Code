#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char stu_name[20];
	long int stu_num;
	int stu_age;
	struct student *next;
};


struct student *creat_stu()
{
	struct student *head = malloc(sizeof(struct student));
	if(head == NULL)
	{
		printf("creat_stu fail\n");
	}

	head->next = NULL;

	return head;
}


void insert_stu(struct student *head,long int num,char *name,int age)
{
	struct student *new = malloc(sizeof(struct student));
	struct student *p = head;

	if(new == NULL)
        {
                printf("creat new fail\n");
		return;
        }

	new->next = p->next;
	p->next = new;
	new->stu_num = num;
	strcpy(new->stu_name,name);
	new->stu_age = age;
}

int empty(struct student *head)
{
	if(head->next == NULL)
	{
		printf("is empty\n");
		return 1;
	}

	return 0;
}

void del_stu(struct student *head)
{
	if(empty(head))
	{
		return;
	}
	struct student *del = head->next;

	head->next =del->next;

	free(del);
}

int length(struct student * head)
{

	struct student * p = head;
	int  i = 0;
	while(p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;

}

void stu_sort(struct student *head)
{
	struct student *p = head;
	struct student *q;

	int i = 0;
	char name1[10];
	while(i < length(head))
	{
		p = head->next;
		while(p->next != NULL)
		{
			q = p->next;
			if( p->stu_num > q->stu_num )
			{
				int z = p->stu_num;
				p->stu_num = q->stu_num;
				q->stu_num = z;

				strcpy(name1,p->stu_name);
				strcpy(p->stu_name,q->stu_name);
				strcpy(q->stu_name,name1);
				
				int s = p->stu_age;
				p->stu_age = q->stu_age;
				q->stu_age = s;
			}
			p = q;
		}
	i++;	
	
	}
}

int main()
{
	int x;
	long int num;
	char name[20];
	int age;
	struct student *head = creat_stu();
	struct student *p;
	struct student *s = head;
	struct student *w;
	
	char buff[50];
	FILE *fp = fopen("1.txt","a+");
	
	//先在终端打应以前保存的数据
	while(1)
	{
		int num1 = fread(buff,1,20,fp);
		if(num1 == 0)
		{
			break;
		}
		fwrite(buff,1,num1,stdout);
	}

	FILE *fp1 = fopen("work3.c","r");
	if(fp == NULL)
	{
		perror("fopen error");
	}

	while(1)
	{
		printf("请输入要插入学生的信息\n");
		scanf("%ld",&num);
		if(num == 0)
		{
			break;
		}
		scanf("%s",name);
		scanf("%d",&age);
		insert_stu(s,num,name,age);
		s = s->next;
	}

	w = head->next;//第一个学生
	while(w != NULL)
	{
		struct student *q = w;
		while(q->next != NULL)//判断第二个学生是否为最后一个
		{
			if(w->stu_num == q->next->stu_num)
			{
				del_stu(q);
				break;
			}
			q = q->next;
		}
		w = w->next;
	}
	
	stu_sort(head);

	p = head;
	printf("全部学生信息：\n");
	for(int i = 0;p->next != NULL ;i++)
	{
		p = p->next;
		printf("%-10ld\t%-10s\t%-10d\n",p->stu_num,p->stu_name,p->stu_age);
		int x = fprintf(fp,"学号:%-10ld\t姓名:%-10s年龄:%-10d\n",p->stu_num,p->stu_name,p->stu_age);
		if(x == -1)
		{
			perror("fprintf error");
		}
	}

	fclose(fp);

	return 0;
}
