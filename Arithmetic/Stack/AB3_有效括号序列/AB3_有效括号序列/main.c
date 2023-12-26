//  AB3_有效括号序列
//  例如：输入"{}[]()"、"{[()]}"，则为有效的括号序列
//      输入"{}[(])"、"{{]]()"，则为无效的括号序列

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
    if(Empty(T))
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
    if(Empty(T))
    {
        //printf("error\n");
        return 0;
    }
    return T->head->next->data;
}

int main(int argc, const char * argv[])
{
    char bracketArr[] = "(]{}";
    struct HeadNode *T = StackInit();
    
    int sz = strlen(bracketArr);
    int i = 0;
    while(i < sz)
    {
        if((int)bracketArr[i] == (TopOperation(T)+2) || (int)bracketArr[i] == (TopOperation(T)+1))
        {
            PopOperation(T);
        }
        else
        {
            PushOperation(T, (int)bracketArr[i]);
        }
        i++;
    }
    if(Empty(T))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    
    return 0;
}
