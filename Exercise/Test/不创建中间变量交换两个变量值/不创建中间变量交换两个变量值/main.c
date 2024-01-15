//
//  main.c
//  不创建中间变量交换两个变量值

#include <stdio.h>

int main(int argc, const char * argv[])
{
    //  使用中间变量
//    int a = 10;
//    int b = 20;
//    int c = 0;
//    printf("a=%d,b=%d\n",a,b);
//    c = a;
//    a = b;
//    b = c;
//    printf("a=%d,b=%d\n",a,b);
    
    //  不使用中间变量
    //  这种方法有弊端，当a b 两个值接近该类型的最大值时，两个相加就会超过类型的范围，导致相加之后的值就会出错
    //  这种方法只适用于较小的值
//    int a = 10;
//    int b = 20;
//    printf("a=%d,b=%d\n",a,b);
//    a = a + b;
//    b = a - b;
//    a = a - b;
//    printf("a=%d,b=%d\n",a,b);
    
    
    //  该方法不用担心超数据类型的范围
    // 异或运算支持交换率
    // a ^ a = 0
    // a ^ 0 = a
    int a = 10;
    int b = 20;
    printf("a=%d,b=%d\n",a,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a=%d,b=%d\n",a,b);
    
    
    
    return 0;
}
