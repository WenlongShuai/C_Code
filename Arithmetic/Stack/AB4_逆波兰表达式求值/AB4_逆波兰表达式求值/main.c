//  AB4_逆波兰表达式求值
//  输入：["2","1","+","4","*"]   输出：12
//  输入：["2","0","+"]   输出：2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int StringToNum(char *str)
{
    int strSize = strlen(str);
    int ret = 0;
    int i = 0;
    if(str == NULL)
    {
        return -1;
    }
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            ret += (str[i] - '0') * (int)pow(10, strSize-i-1);
        }
        else
        {
            ret = (int)(str[i]);
        }
        i++;
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    struct HeadNode *T = StackInit();
    char tokens[][3] = {"2","3","+","5","-"};
    int x = 0;
    int y = 0;
    char symbol = '0';
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int i = 0;
    int result = 0;
    
    while(i < tokensSize)
    {
        PushOperation(T,StringToNum(tokens[i]));
        if(TopOperation(T) == '+' || TopOperation(T) == '-' || TopOperation(T) == '*' || TopOperation(T) == '/')
        {
            symbol = TopOperation(T);
            PopOperation(T);
            x = TopOperation(T);
            PopOperation(T);
            y = TopOperation(T);
            if(symbol == '+')
            {
                result = x + y;
            }
            else if(symbol == '-')
            {
                result = x - y;
            }
            else if(symbol == '*')
            {
                result = x * y;
            }
            else
            {
                result = x / y;
            }
            PushOperation(T, result);
        }
        
        i++;
    }
    
    printf("%d\n",result);
   
    return 0;
}
