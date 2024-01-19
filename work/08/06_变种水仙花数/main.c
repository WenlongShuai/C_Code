//
//  main.c
//  06_变种水仙花数
//  1461 == 1*461+14*61+146*1
//  655 == 6*55+65*5

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    
    int k = 0;
    for(i=10000;i<100000;i++)
    {
        int sum = 0;
        int j = 1;
        while(j<=4)
        {
            k = (int)pow(10,j);
            sum += (i/k)*(i%k);
            j++;
        }
        
        if(sum == i)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
