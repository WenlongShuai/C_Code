//  09_Fibonacci数列
//描述：Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i-1] + F[i-2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13,...在Fibonacci数列中的数我们称为Fibonacci数。
//给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
//输入描述：
//输入为一个正整数N(1 ≤ N ≤ 1,000,000)
//输出描述：
//输出一个最小的步数变为Fibonacci数
//输入：15
//输出：2

#include <stdio.h>
#include <stdlib.h>

int findFibonacci(int N)
{
    int f0 = 0;
    int f1 = 1;
    int fibonacii = 0;
    int step = 0;
    
    while(1)
    {
        fibonacii = f0+f1;
        f0 = f1;
        f1 = fibonacii;
        if(N >= f0 && N <= f1)
        {
            abs((N-f0))>abs((N-f1))?(step=abs(N-f1)):(step=abs(N-f0));
            return step;
        }
    }
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    
    int ret = findFibonacci(num);
    printf("%d\n",ret);
    
    return 0;
}
