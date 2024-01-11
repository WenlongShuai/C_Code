//  BC14_Birthdate
//输入一个出生日期（包括年月日），然后把该日期的年月日分别输出
//20231221
//year=2023
//month=12
//date=21

#include <stdio.h>

int main(int argc, const char * argv[])
{
    //方法一，通过字符串处理
    //输入年月日
    char year[5] = {0};
    char month[3] = {0};
    char date[3] = {0};
    scanf("%4s%2s%2s",year,month,date);

    //输出
    printf("year=%s\n",year);
    printf("month=%02s\n",month);
    printf("date=%02s\n",date);
    
    //方法二，通过整数处理
//    //输入年月日
//    int year = 0;
//    int month = 0;
//    int date = 0;
//    scanf("%4d%2d%2d",&year,&month,&date);
//
//    //输出
//    printf("year=%d\n",year);
//    printf("month=%02d\n",month);
//    printf("date=%02d\n",date);
    
    return 0;
}
