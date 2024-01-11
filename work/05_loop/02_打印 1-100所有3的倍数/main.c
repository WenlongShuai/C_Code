//  02_打印 1-100所有3的倍数


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    int count = 0;
    
    //  方法一
//    for(i=1;i<=100;i++)
//    {
//        if(i % 3 == 0)
//        {
//            printf("%d ",i);
//            count++;
//        }
//    }
//    printf("\n%d\n",count);
    
    //  方法二
    for(i=3;i<=100;i+=3)
    {
        printf("%d ",i);
        count++;
    }
    printf("\n%d\n",count);
    return 0;
}
