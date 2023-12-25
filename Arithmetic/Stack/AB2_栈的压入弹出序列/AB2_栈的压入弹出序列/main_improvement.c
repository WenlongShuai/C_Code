//  AB2_栈的压入弹出序列
//  两个序列，一个入栈序列，一个出栈序列。
//  判断入栈序列的出栈是否等于出栈序列


#include <stdio.h>
#include <string.h>
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
    T->head = node;
    node->next = NULL;
    return T;
}

int Empty(struct HeadNode *T)
{
    if(T->head->next != NULL)
    {
        return 1;
    }
    return 0;
}

void PrintStack(struct HeadNode *T)
{
    struct StackNode* temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    temp = T->head->next;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void PushOperation(struct HeadNode *T,int d)
{
    struct StackNode *p = (struct StackNode *)malloc(sizeof(struct StackNode));
    p->next = T->head->next;
    T->head->next = p;
    p->data = d;
}

void PopOperation(struct HeadNode *T)
{
    if(!Empty(T))
    {
        printf("error\n");
        return ;
    }
    struct StackNode *p = T->head->next;
    T->head->next = p->next;
    p = NULL;
    free(p);
}

int TopOperation(struct HeadNode *T)
{
    return T->head->next->data;
}

int main()
{
    int pushList[5] = {1,2,3,4,5};
    int popList[5] = {5,4,3,1,2};
    int i = 0;
    int j = 0;
    int flag = 1;
    struct HeadNode *T = StackInit();
    int pushSZ = sizeof(pushList)/sizeof(pushList[0]);
    int popSZ = sizeof(popList)/sizeof(popList[0]);
    for(i = 0;i < popSZ;i++)
    {
        while(j < pushSZ && (!Empty(T) || (TopOperation(T) != popList[i])) )
        {
            PushOperation(T, pushList[j]);
            j++;
        }
        if(TopOperation(T) == popList[i])
        {
            PopOperation(T);
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    return 0;
}

