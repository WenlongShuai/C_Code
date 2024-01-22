//  main.c
//  04_X形图案
//  输入：5
//  输出：
//     *   *
//      * *
//       *
//      * *
//     *   *

//  把整体看成一个矩形，相当于二维数组，然后找规律，发现当横坐标等于纵坐标的地方就是*，或者当横坐标加上纵坐标等于二维数组的行或者列减一的地方也是*

#include <stdio.h>

void printXDesign(int num)
{
    int i = 0;
    int j = 0;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(i == j)
            {
                printf("*");
            }
            else if(i+j == num-1)
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
    int num = 0;
    scanf("%d",&num);
    printXDesign(num);
    return 0;
}
