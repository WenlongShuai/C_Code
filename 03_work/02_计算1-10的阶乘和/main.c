//  02_计算1-10的阶乘和
//  1！+2！+3！+....+10!

#include <stdio.h>

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main(int argc, const char * argv[])
{
    int i = 1;
    int sum = 0;
    for (i=1; i<=10; i++)
    {
        sum += factorial(i);
    }
    printf("%d\n",sum);
    return 0;
}
