//  计算带余除法

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int a = 0;
    int b = 0;
    
    scanf("%d %d",&a,&b);
    
    int iquo = a / b;  //整数商
    int irem = a % b; //余数
    printf("%d %d\n",iquo,irem);
    
    
    return 0;
}
