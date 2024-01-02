//  03_两个数的最大公约数

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);
    int i = 0;
    int c = 0;
    
    //  方法一
//    int n = a < b?a:b;
//    for(i=n;i>0;i--)
//    {
//        if((a%i==0) && (b%i == 0))
//        {
//            printf("%d\n",i);
//            break;
//        }
//    }
    
    //方法二
    while(a%b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d\n",b);
    
    return 0;
}
