//  main.c
//  求两个数的最小公倍数
//  输入：5 7
//  输出：35
//       6 8
//       24

#include <stdio.h>
#include <math.h>

int getGCD(int num1,int num2)   //得到最大公因数
{
    int c = 0;
    while(num1%num2)
    {
        c = num1 % num2;
        num1 = num2;
        num2 = c;
    }
    return num2;
}

int getLCM(int num1,int num2)   //得到最小公倍数
{
    int count = 1;
    int i = 2;

    while(1)
    {
        if((num1%i!=0) || (num2%i!=0))
        {
            i++;
        }
        if((num1%i==0) && (num2%i==0))
        {
            count *= i;
            num1 /= i;
            num2 /= i;
        }
        if(getGCD(num1,num2) == 1)
        {
            break;
        }
    }
    return num1 * num2 * count;
}

int main(int argc, const char * argv[])
{
    int num1 = 0;
    int num2 = 0;
    int ret = 0;
    scanf("%d%d",&num1,&num2);
    ret = getLCM(num1,num2);
    printf("%d\n",ret);
    return 0;
}
