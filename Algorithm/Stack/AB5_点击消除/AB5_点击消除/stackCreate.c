//  stackCreate.c

#include "stackCreate.h"

#include <stdlib.h>

//每个元素的结点
struct StackNode
{
    int data;
    struct StackNode *next;
};

//头结点
struct HeadNode
{
    struct StackNode *head;
};

struct HeadNode* StackInit()
{
    struct StackNode* node = (struct StackNode *)malloc(sizeof(struct StackNode));
    struct HeadNode* T = (struct HeadNode *)malloc(sizeof(struct HeadNode));
    if(node==NULL || T==NULL)
    {
        printf("%s\n",strerror(errno));
        return NULL;
    }
    T->head = node;
    node->next = NULL;
    return T;
}

int Empty(struct HeadNode *T)
{
    if(T->head->next != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void PrintStack(struct HeadNode *T)
{
    struct StackNode* temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    if(temp==NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }
    temp = T->head->next;
    while(temp != NULL)
    {
        printf("%c\n",(char)temp->data);
        temp = temp->next;
    }
}

void PushOperation(struct HeadNode *T,int d)
{
    struct StackNode *p = (struct StackNode *)malloc(sizeof(struct StackNode));
    if(p==NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }
    p->next = T->head->next;
    T->head->next = p;
    p->data = d;
}

void PopOperation(struct HeadNode *T)
{
    if(Empty(T))
    {
        printf("error\n");
        return ;
    }
    struct StackNode *p = T->head->next;
    T->head->next = p->next;
    
    free(p);//因为free掉了这块内存之后，p指针指向的地址还是原来那块内存。这样p就会成为野指针。所以释放完了，要将p指向的地址置为NULL。
    p = NULL;
}

int TopOperation(struct HeadNode *T)
{
    if(Empty(T))
    {
        //printf("error\n");
        return 0;
    }
    return T->head->next->data;
}
