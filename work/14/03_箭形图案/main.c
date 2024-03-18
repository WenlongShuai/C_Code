//  03_箭形图案
//
//描述：KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的箭形图案。
//输入描述：多组输入，每行一个整数（2~20）。
//输出描述：针对每行输入，输出用“*”组成的箭形。
//
//输入：2
//输出：
//    *
//  **
//***
//  **
//    *
//输入：3
//输出：
//      *
//    **
//  ***
//****
//  ***
//    **
//      *


#include <stdio.h>

//方法一
//void arrowsPattern(int n)
//{
//    int i = 0;
//    int j = 0;
//    for(i=0;i<=n;i++)
//    {
//        for(j=0;j<=2*n-i;j++)
//        {
//            if(i+j >= 2*n-i)
//                printf("*");
//            else
//                printf(" ");
//        }
//        printf("\n");
//    }
//    for(i=n-1;i>=0;i--)
//    {
//        for(j=0;j<=2*n-i;j++)
//        {
//            if(i+j >= 2*n-i)
//                printf("*");
//            else
//                printf(" ");
//        }
//        printf("\n");
//    }
//}


//方法二
void arrowsPattern(int n)
{
    int i = 0;
    
    //上半部分的n行
    for(i=0;i<n;i++)
    {
        int j = 0;
        //打印‘ ’
        for(j=0;j<2*(n-i);j++)
        {
            printf(" ");
        }
        //打印‘*’
        for(j=0;j<i+1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    //下半部分的n+1行
    for(i=0;i<n+1;i++)
    {
        int j = 0;
        //打印‘ ’
        for(j=0;j<2*i;j++)
        {
            printf(" ");
        }
        //打印‘*’
        for(j=0;j<n+1-i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    int n = 0;
    while(scanf("%d",&n) == 1)
    {
        arrowsPattern(n);
    }
    return 0;
}
