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

void arrowsPattern(int n)
{
    int i = 0;
    int j = 0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=2*n-i;j++)
        {
            if(i+j <= 2*n && i+j >= 2*n-i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
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
