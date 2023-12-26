//define关键字 -------- 宏定义

#include <stdio.h>

#define NUM 10   //宏定义一个变量

//MAX--->宏名    (a,b)--->宏的参数   (a>b?a:b)--->宏体
#define MAX(a,b) (a>b?a:b)   //宏定义一个函数

#define MIN(a,b) {if(a<b) printf("Min = %d\n",a);else printf("Min = %d\n",b);}

int main()
{
    int a = NUM;    //编译器会将该语句替换成 int a = 10
    printf("%d\n",a);
    
    int arr[NUM] = {0};    //编译器会将该语句替换成 int arr[10] = {0}
    printf("%d\n",arr[2]);
    
    int x = 20;
    int y = 30;
    int r = MAX(x, y);    //编译器会将该语句替换成 int r = (x>y?x:y)
    printf("%d\n",r);
    
    MIN(x, y);      //编译器会将该语句替换成
                    //{if(x<y) printf("Min = %d\n",x);else printf("Min = %d\n",y);}
    return 0;
}
