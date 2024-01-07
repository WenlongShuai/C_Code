//  AB6_表达式求值
//  写一个计算器，支持加减乘和扣号运算。

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stackCreate.h"


int calculate(char symbol,int x,int y)
{
    int ret = 0;
    switch(symbol)
    {
        case '+':
            ret = x + y;
            break;
        case '-':
            ret = x - y;
            break;
        case '*':
            ret = x * y;
            break;
        case '/':
            if(y != 0)
            {
                ret = x / y;
            }
            break;
    }
    return  ret;
}


//本方法主要采用辅助栈+递归。
//两个辅助栈：运算符栈（存放相应的运算符）、数字栈（存放表达式的数字及计算结果）。
int expressionRecursion(char* str,int i)
{
    static int index = 0;
    int a = 0;   //运算符后一个数字
    int b = 0;   //运算符前一个数字
    int result = 0;
    char symbol = '\0';
    struct HeadNode* operator = StackInit();  //运算符栈
    struct HeadNode* nums = StackInit();    //数字栈

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
        if(str[i] == '\0')
        {
            break;
        }
        if( (str[i] != '(' && str[i] != ')') && ((TopOperation(operator) == str[i] || TopOperation(operator)+2 == str[i] || TopOperation(operator)-2 == str[i] || TopOperation(operator)+5 == str[i] || TopOperation(operator)-5 == str[i]) || ((str[i] == '+' || str[i] == '-') && (TopOperation(operator) == '*' || TopOperation(operator) == '/')))) //运算栈的栈顶元素优先级高于等于即将入栈的运算符，则就把运算符栈栈顶的运算符拿出来先计算，然后再把即将入栈的运算符入栈到运算符栈中
        {
            //如果判断出即将入栈的运算符优先级大于栈顶运算符，那么就拿出来计算，计算出的结果入栈到数字栈中。并且用即将入栈的运算符跟栈内的其他运算符比较，如果优先级一样，则继续出栈运算并将相应的结果存在数字栈中，直到遇到优先级低的或者运算符栈为空就停止运算。最后将该即将入栈的运算符入栈。
            do
            {
                symbol = TopOperation(operator);
                PopOperation(operator);
                a = TopOperation(nums);
                PopOperation(nums);
                b = TopOperation(nums);
                PopOperation(nums);
                PushOperation(nums, calculate(symbol,b,a));
            }while((TopOperation(operator) == str[i] || TopOperation(operator)+2 == str[i] || TopOperation(operator)-2 == str[i] || TopOperation(operator)+5 == str[i] || TopOperation(operator)-5 == str[i]));
            PushOperation(operator, str[i]);
        }
        else if((TopOperation(operator) == '+' || TopOperation(operator) == '-') && (str[i] == '*' || str[i] == '/'))//运算栈的栈顶元素优先级低于即将入栈的运算符，则就把即将入栈的运算符入栈到运算符栈中
        {
            PushOperation(operator, str[i]);
        }
        else if((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
        {
            PushOperation(operator, str[i]);
        }
        //如果判断出即将入栈的符号是‘(’，则就进入递归处理
        else if(str[i] == '(')
        {
            i++;
            int x = expressionRecursion(str,i);
            i = index;
            PushOperation(nums, x);
            
        }
        //递归的停止条件
        else if(str[i] == ')')
        {
            index = i;
            break;
        }
        i++;
    }
    while(!Empty(operator))
    {
        symbol = TopOperation(operator);
        PopOperation(operator);
        a = TopOperation(nums);
        PopOperation(nums);
        b = TopOperation(nums);
        PopOperation(nums);
        PushOperation(nums, calculate(symbol,b,a));
    }
    
    return  TopOperation(nums);
}

int main(int argc, const char * argv[])
{
    char* str = "3+2*3*4-1";//2-4*4+5
    int ret = expressionRecursion(str,0);

    printf("%d\n",ret);
    
    return 0;
}
