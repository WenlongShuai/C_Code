#ifndef __STU_LINK_H__
#define __STU_LINK_H__

struct student *creat_stu();
void insert_stu(struct student *head,long int num,char *name,int age);
int empty(struct student *head);
void del_stu(struct student *head);

#endif
