//  AB6_表达式求值
//  写一个计算器，支持加减乘和扣号运算。

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

int calculate(char symbol,int x,int y)
{
    int ret = 0;
    switch(symbol)
    {
        case '+':
            ret = x + y;
        case '-':
            ret = x - y;
        case '*':
            ret = x * y;
        case '/':
            if(y != 0)
            {
                ret = x / y;
            }
    }
    return  ret;
}

int main(int argc, const char * argv[])
{
    char* str = "1+2";
    struct HeadNode* operator = StackInit();  //运算符栈
    struct HeadNode* nums = StackInit();    //数字栈
    int i = 0;
    int a = 0;   //运算符后一个数字
    int b = 0;   //运算符前一个数字
    int result = 0;
    char symbol = '\0';
    
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = 0;
            while(str[i] >= '0' && str[i] <= '9')
            {
                result = result * 10 + (str[i] - 48);
                i++;
            }
            PushOperation(nums, result);
        }
        
        if((str[i] == '+' || str[i] == '-') && (TopOperation(operator) == '*' || TopOperation(operator) == '/') )  //运算栈栈顶元素优先级高于即将入栈的运算符
        {
            symbol = TopOperation(operator);
            a = TopOperation(nums);
            PopOperation(nums);
            b = TopOperation(nums);
            PopOperation(nums);
            PushOperation(nums, calculate(symbol,b,a));
        }
        else if(str[i] == ')' && TopOperation(operator) == '(')
        {
            PopOperation(operator);
        }
        else if(str[i] == '(' || (TopOperation(operator) == '+' || TopOperation(operator) == '-') && (str[i] == '*' || str[i] == '/'))//运算栈栈顶元素优先级低于即将入栈的运算符
        {
            PushOperation(operator, str[i]);
        }
        else if(Empty(operator) && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
        {
            PushOperation(operator, str[i]);
        }
        else
        {
            symbol = TopOperation(operator);
            a = TopOperation(nums);
            PopOperation(nums);
            b = TopOperation(nums);
            PopOperation(nums);
            PushOperation(nums, calculate(symbol,b,a));
        }
        i++;
    }
    printf("%d\n",TopOperation(nums));
    return 0;
}
