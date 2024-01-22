//  main.c
//  05_获得月份的天数
//  输入：2008 2
//  输出：29

#include <stdio.h>


//  方法一
//int getDayOfMonth(int year,int month)
//{
//    int day = 0;
//    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//    {
//        //在这些月份中每月有31天
//        day = 31;
//    }
//    else if(month == 4 || month == 6 || month == 9 || month == 11)
//    {
//        //在这些月份中每月有30天
//        day = 30;
//    }
//    else
//    {
//        //特殊月份2月
//        //如果是平年，2月则有28天
//        //如果是闰年，2月则有29天
//        if((year%4==0 && year%100!=0) || year%400==0)
//        {
//            //闰年
//            day = 29;
//        }
//        else
//        {
//            //平年
//            day = 28;
//        }
//    }
//    return day;
//}

//  方法二
int getDayOfMonth(int year,int month)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        //闰年
        days[1]++;
    }
    return days[month-1];
}

int main(int argc, const char * argv[])
{
    int year = 0;
    int month = 0;
    scanf("%d%d",&year,&month);
    int day = getDayOfMonth(year,month);
    printf("%d\n",day);
    return 0;
}
