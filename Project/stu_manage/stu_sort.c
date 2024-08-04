#include "stu_sort.h"
 struct student
{
        char stu_name[20];
        long int stu_num;
        int stu_age;
        struct student *next;
};
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

