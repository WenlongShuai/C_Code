//  02_计算一个数的每位之和
//  使用递归实现
//  输入：1234   输出：10
//      1729        19

#include <stdio.h>

int digitSum(n)
{
    int digit = n % 10;
    if(n > 0)   //这种递归会出现当n小于10的时候，还会执行一次digitSum(0)
    {
        return digit + digitSum(n/10);
    }
    return digit;
    
//    int digit = n % 10;
//    if(n < 10)  //这种递归当n小于10的时候，就直接返回这个数，比上面那个递归少执行一次
//    {
//        return digit;
//    }
//    else
//    {
//        return digit + digitSum(n/10);
//    }
    
//    if(n > 9)
//    {
//        return digitSum(n/10)+n%10;
//    }
//    else
//    {
//        return n;
//    }
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    int x = digitSum(num);
    printf("%d\n",x);
    
    return 0;
}
