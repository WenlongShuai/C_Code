//  main.c
//  03_获取整数二进制序列中的偶数位和奇数位


#include <stdio.h>

//  方法一
//void getBinaryOddEven(int binaryNum)
//{
//    int i = 0;
//    int oddEven = 0;  //奇数
//    int odd = 0;   //偶数

//    printf("偶数：");
//    for(i=0;i<32;i++)
//    {
//        if(i%2 == 0)
//        {
//            odd = (binaryNum>>i) & 1;
//            printf("%d",odd);
//        }
//    }
//    printf("\n");
//    printf("奇数：");
//    for(i=0;i<32;i++)
//    {
//        if(i%2 != 0)
//        {
//            oddEven = (binaryNum>>i) & 1;
//            printf("%d",oddEven);
//        }
//    }
//}


//  方法二
void getBinaryOddEven(int binaryNum)
{
    int i = 0;
    int oddEven = 0;  //奇数
    int odd = 0;   //偶数
    
    printf("偶数：");
    for(i=0;i<32;i+=2)
    {
        odd = (binaryNum>>i) & 1;
        printf("%d",odd);

    }
    printf("\n");
    printf("奇数：");
    for(i=1;i<32;i+=2)
    {
        oddEven = (binaryNum>>i) & 1;
        printf("%d",oddEven);
    }
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    getBinaryOddEven(num);
    return 0;
}
