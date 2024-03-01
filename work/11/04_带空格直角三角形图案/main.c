//  04_带空格直角三角形图案
//  输入一个数字，输出一个直角三角形，每个'*'后面跟一个空格
// 输入：5
// 输出：
//        *
//      * *
//    * * *
//  * * * *
//* * * * *

#include <stdio.h>

void outputRightTriangle(int num)
{
    int i = 0;
    int j = 0;
    int count = 2 * num;
    for(i=0;i<num;i++)
    {
        for(j=0;j<count-2*(i+1);j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    int input = 0;
    while(scanf("%d",&input) == 1)
    {
        outputRightTriangle(input);
    }
    
    return 0;
}
