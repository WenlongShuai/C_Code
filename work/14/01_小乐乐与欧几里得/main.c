//  01_小乐乐与欧几里得
// 小乐乐最近在课上学习了如何求两个正整数的最大公约数与最小公倍数，但是他竟然不会求两个正整数的最大公约数与最小公倍数之和。
//输入描述：每组输入包含两个正整数n和m。(1 ≤ n ≤ 109，1 ≤ m ≤ 109)
//输出描述：对于每组输入，输出一个正整数，为n和m的最大公约数与最小公倍数之和。
//输入：10 20
//输出：30

#include <stdio.h>

long getDivisor(long m, long n)
{
    while(m % n)
    {
        long c = m % n;
        m = n;
        n = c;
    }
    return n;
}

//long getMultiple(long m, long n)
//{
//    long lcm = (m>n)?m:n;
//    while(1)
//    {
//        if(lcm%m==0 && lcm%n==0)
//        {
//            return lcm;
//        }
//        lcm++;
//    }
//}

long divisorMultipleSum(long m, long n)
{
    long divisor = getDivisor(m, n);
//    long multiple = getMultiple(m, n);  //这种实现方法效率比较低
    long multiple = m*n/divisor;   //最小公倍数===》两个数的乘积除以最大公约数
    return divisor+multiple;
}

int main(int argc, const char * argv[])
{
    long m = 0;
    long n = 0;
    scanf("%ld%ld",&m,&n);
    long ret = divisorMultipleSum(m,n);
    printf("%ld\n",ret);
    return 0;
}
