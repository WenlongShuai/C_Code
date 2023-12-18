//分支语句
//switch
//注意事项：
// 1、switch里面的值必须为常量或者常量表达式，不能为变量
//2、如果没有特殊需求，则在每条case语句之后都加个break语句，
//   防止switch语句的穿透行为（找到case入口之后，一直执行到switch语句结束）。

#include <stdio.h>

int main()
{
    int day = 0;
    scanf("%d",&day);
    switch(day)
    {
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;
    default:
        printf("input number error\n");
        break;
    }
    return 0;
}
