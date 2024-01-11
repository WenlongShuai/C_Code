//  02_计算1-10的阶乘和
//  1！+2！+3！+....+10!

#include <stdio.h>

//  方法一：递归方法
//int factorial(int n)
//{
//    if(n == 1)
//    {
//        return 1;
//    }
//    return n*factorial(n-1);
//}
//
//int main(int argc, const char * argv[])
//{
//    int i = 1;
//    int sum = 0;
//    for (i=1; i<=10; i++)
//    {
//        sum += factorial(i);
//    }
//    printf("%d\n",sum);
//    return 0;
//}


//  方法二：循环方法
int main()
{
    int i = 1;
    int j = 1;
    int ret = 1;
    int n = 0;
    int sum = 0;
    scanf("%d",&n);
    
    //  方法一：用双层循环
//    for(i = 1;i <= n;i++)
//    {
//        ret = 1;
//        for(j = 1;j <= i;j++)
//        {
//            ret = ret * j;
//        }
//        sum += ret;
//    }
//    printf("%d\n",sum);
    
    //  方法二：一层循环解决阶乘和相加的操作
    for(i = 1;i <= n;i++)
    {
        ret = ret * i;
        sum += ret;
    }
    printf("%d\n",sum);
    return 0;
}
