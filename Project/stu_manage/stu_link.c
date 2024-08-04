#include "stu_link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

