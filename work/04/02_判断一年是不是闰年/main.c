//  02_判断一年是不是闰年
//  判断条件：1、能被4整除且不能被100整除
//          2、能被400整除


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int year = 0;
//    scanf("%d",&year);
//    if((year%4==0 && year%100!=0) || year%400==0)
//    {
//        printf("闰年\n");
//    }
//    else
//    {
//        printf("不是闰年\n");
//    }
    int count = 0;
    for (year=1000; year<=2000; year++)
    {
        if((year%4==0 && year%100!=0) || year%400==0)
        {
            printf("%d ",year);
            count++;
        }
    }
    printf("%d\n",count);
       
    return 0;
}
