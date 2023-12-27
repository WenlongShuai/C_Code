//  AB5_点击消除
//  输入：abbc     输出：ac
//  输入：bbbbb    输出：b
//  输入：abba     输出：0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("%c\n",(char)temp->data);
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
    char *str = "bbbbba";
    int i = 1;
    int ret = 0;
    int j = 0;
    int x = 0;
    int strSize = strlen(str);
    char surplus[10] = {0};
    char convert[10] = {0};
    struct HeadNode* T = StackInit();
    PushOperation(T, (int)str[0]);
    while(i < strSize)
    {
        if((int)str[i] == TopOperation(T))
        {
            PopOperation(T);
        }
        else
        {
            PushOperation(T, (int)str[i]);
        }
        i++;
    }
    if(Empty(T))
    {
        printf("0\n");
    }
    else
    {
        while(!Empty(T))
        {
            ret = TopOperation(T);
            surplus[j] = ret;
            PopOperation(T);
            j++;
        }
        for(x = 0;x < j;x++)
        {
            convert[x] = surplus[j-x-1];
        }
        printf("%s\n",convert);
    }
    
    return 0;
}
