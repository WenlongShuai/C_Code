//  main.c
//  03_水仙花数
//  水仙花数就是n位数字，每一个位数的n次方之和等于该数
// 153 == 1^3+5^3+3^3

#include <stdio.h>
#include <math.h>

void narcissisticNumber(int num)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int n = 0;
    for(i=0;i<num;i++)
    {
        j = i;
        while(j)
        {
            n++;
            j /= 10;
        }
        j = i;
        while(j)
        {
            sum += pow(j%10,n);
            j /= 10;
        }
        if(i == sum)
        {
            printf("%d ",i);
        }
        sum = 0;
        n = 0;
    }
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    
    narcissisticNumber(num);
    return 0;
}
