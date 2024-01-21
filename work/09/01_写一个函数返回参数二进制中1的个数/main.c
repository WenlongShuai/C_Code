//  main.c
//  01_写一个函数返回参数二进制中1的个数

#include <stdio.h>


//  方法一
//  使用 数字&1 的方法
//  数字&1之后，数字就左移i位
//int numberOf1(int binaryNum)
//{
//    int i = 0;
//    int count = 0;
//    for(i=0;i<32;i++)
//    {
//        //if((binaryNum & (1<<i)) == 1<<i)
//        //if(((binaryNum>>i) & 1) == 1)
//        if((binaryNum & (1<<i)))
//        {
//            count++;
//        }
//    }
//
//    return count;
//}

//  方法二
//  使用 数字%2 得到该数字二进制最低位的数字
//  然后再使用 数字/2 得到新的数字，该新的数字为前一个数字丢弃最低位后的得到的
//  这样就可以依次得到最开始数字的二进制每一位
//  注意：这个方法只适合于无符号数（整数）
//  如果要使用于有符号数字，那么就把函数的形参改为无符号型。这样在进行处理的时候就把有符号数强制转换为无符号数
//int numberOf1(int binaryNum)  //适用于无符号数

//int numberOf1(unsigned int binaryNum)  //适用于有符号数
//{
//    int count = 0;
//    while(binaryNum)
//    {
//        if(binaryNum%2 == 1)
//        {
//            count++;
//        }
//        binaryNum /= 2;
//    }
//
//    return count;
//}


//  方法三
//  使用 n = n & (n-1)  --->n就等于n-1的值
//  一直转换，直到n为0
int numberOf1(int binaryNum)  //适用于有符号数
{
    int count = 0;
    while(binaryNum)
    {
        binaryNum = binaryNum & (binaryNum - 1);
        count++;
    }

    return count;
}

int main(int argc, const char * argv[])
{
    int num = 0;
    int count = 0;
    scanf("%d",&num);
    count = numberOf1(num);
    printf("%d\n",count);
    return 0;
}
