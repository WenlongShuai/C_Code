//  02_空心正方形图案
//
//描述：该任务是打印用“*”组成的“空心”正方形图案。
//输入描述：
//多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“*”的数量。
//输出描述：
//针对每行输入，输出用“*”组成的“空心”正方形，每个“*”后面有一个空格。
//输入：4
//输出：
//* * * *
//*     *
//*     *
//* * * *
#include <stdio.h>

void showPattern(int n)
{
    int i = 0;
    int j = 0;
//    for(i=0;i<n;i++)
//    {
//        if(i==0 || i==(n-1))
//        {
//            for(j=0;j<n;j++)
//            {
//                printf("* ");
//            }
//        }
//        else
//        {
//            for(j=0;j<n;j++)
//            {
//                if(j==0 || j==(n-1))
//                {
//                    printf("* ");
//                }
//                else
//                {
//                    printf("  ");
//                }
//            }
//        }
//        printf("\n");
//    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1)
            {
                printf("* ");
            }
            else
                printf("  ");
        }
        
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    int n = 0;
    
    while(scanf("%d",&n) == 1)
    {
        showPattern(n);
    }
    
    return 0;
}
