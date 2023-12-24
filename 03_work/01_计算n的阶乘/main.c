//  01_计算n的阶乘

#include <stdio.h>

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int main(int argc, const char * argv[])
{
    int n = 0;
    int sum = 0;
    scanf("%d",&n);
    sum = factorial(n);
    printf("%d\n",sum);
    return 0;
}
