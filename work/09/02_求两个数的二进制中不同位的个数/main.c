//  main.c
//  02_求两个数的二进制中不同位的个数

#include <stdio.h>

//  方法一
//  使用 '^' 操作符，得到的结果的二进制位为1的就是两个数的二进制不同的位
//  然后在统计结果中的二进制为1的个数
//int differentBits(int binaryNum1,int binaryNum2)
//{
//    int count = 0;
//    int a = binaryNum1^binaryNum2;
//    while(a)
//    {
//        a = a&(a-1);
//        count++;
//    }
//    return count;
//}


//  方法二
//  依次取出两个数的最低位，进行比较是否相等
int differentBits(int binaryNum1,int binaryNum2)
{
    int count = 0;
    int i = 0;
    
    for(i=0;i<32;i++)
    {
        if(((binaryNum1>>i)&1) != ((binaryNum2>>i)&1))
        {
            count++;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[])
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d",&num1,&num2);
    int count = differentBits(num1,num2);
    printf("%d\n",count);
    return 0;
}
