//
//  main.c
//  04_打印棱形

#include <stdio.h>


//  方法一
//  输入num，将1->num作为棱形的上半部分，num+1->2*num-1作为下半部分
//void printRhombus(int num)
//{
//    int i = 0;
//    int j = 0;
//    int x = 0;
//    int count = 1;
//
//    for(i=0;i<2*num-1;i++)
//    {
//        for(j=0;j<2*num-1;j++)
//        {
//            if(i<=num-1)
//            {
//                x = 2*i+1;   //上半部分需要打印‘*’的个数
//                if(i+j == num-1)
//                {
//                    while(x)
//                    {
//                        printf("*");
//                        x--;
//                    }
//                }
//                else
//                {
//                    printf(" ");
//                }
//            }
//            else
//            {
//                if(i-j == num-1)
//                {
//                    x = 2*(i-1-count)+1;  //下半部分需要打印‘*’的个数
//                    while(x)
//                    {
//                        printf("*");
//                        x--;
//                    }
//                    count += 2;
//                }
//                else
//                {
//                    printf(" ");
//                }
//            }
//        }
//        printf("\n");
//    }
//}

//  方法二
//  将棱形分为2部分，每部分都当作一个循环
void printRhombus(int num)
{
    int i = 0;
    int j = 0;
    
    //上半部分
    for(i=0;i<num;i++)
    {
        for(j=num-1-i;j>0;j--)
        {
            printf(" ");
        }
        for(j=0;j<2*i+1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    //下半部分
    for(i=0;i<num-1;i++)
    {
        for(j=0;j<i+1;j++)
        {
            printf(" ");
        }
        for(j=0;j<2*(num-1-i)-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    printRhombus(num);
    
    return 0;
}
