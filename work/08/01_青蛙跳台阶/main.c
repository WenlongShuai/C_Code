//
//  main.c
//  01_青蛙跳台阶
//  青蛙跳台阶，一次可以跳一步台阶或者两步台阶，问n层台阶有几种跳法

#include <stdio.h>


//  青蛙一次有两种选择，1、跳一步台阶。 2、跳两步台阶
//  如果有1个台阶，则有1种跳法
//  如果有2个台阶，则有2种跳法
//  如果有3个台阶，则有3种跳法。
// （第一次先跳一步台阶，还剩2个台阶，2个台阶还有2种跳法）+（第一次先跳两步台阶，还剩一个台阶，2一个台阶1种跳法）
//  ......
//  如果n个台阶，先跳一步台阶，则还有（n-1）个台阶，还有（n-1）中跳法+先跳两步台阶，则还有（n-2）个台阶，还有（n-2）中跳法
//  jumpTheSteps(n-1)+jumpTheSteps(n-2)

int jumpTheSteps(int n)
{
    if(n <= 2)
    {
        return n;
    }
    return  jumpTheSteps(n-1)+jumpTheSteps(n-2);
}

int main(int argc, const char * argv[])
{
    int n = 0;
    scanf("%d",&n);
    
    int count = 0;
    count = jumpTheSteps(n);
    
    printf("%d\n",count);
    return 0;
}
