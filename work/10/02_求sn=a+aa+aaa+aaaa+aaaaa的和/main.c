//  main.c
//  02_求sn=a+aa+aaa+aaaa+aaaaa的和，求前5项的和
//  a是一个数字
//  输入：2+22+222+2222+22222


#include <stdio.h>
#include <math.h>

int sumOf5Items(int num)
{
    int sum = 0;
    int tmp = 0;
    int i = 0;
    for(i=0;i<5;i++)
    {
//        a = num*1+0
//        b = num*10+a;
//        c = num*100+b;
//        d = num*1000+c;
//        e = num*10000+d;
        
        tmp += num*pow(10,i);
        sum += tmp;
    }
    return sum;
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    int ret = sumOf5Items(num);
    printf("%d\n",ret);
    
    return 0;
}
