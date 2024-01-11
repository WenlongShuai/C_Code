//  01_计算n的阶乘

#include <stdio.h>

//  方法一：递归方法
//int factorial(int n)
//{
//    if(n == 1)
//    {
//        return 1;
//    }
//    return n * factorial(n-1);
//}
//
//int main(int argc, const char * argv[])
//{
//    int n = 0;
//    int sum = 0;
//    scanf("%d",&n);
//    sum = factorial(n);
//    printf("%d\n",sum);
//    return 0;
//}

//  方法二：循环方法
int main()
{
    int i = 1;
    int n = 0;
    int ret = 1;
    scanf("%d",&n);
    //for循环
//    for(i = 1;i <= n;i++)
//    {
//        ret = ret * i;
//    }
//    printf("%d\n",ret);
    
    //while循环
    while(i <= n)
    {
        ret = ret * i;
        i++;
    }
    printf("%d\n",ret);
    
    return 0;
}
