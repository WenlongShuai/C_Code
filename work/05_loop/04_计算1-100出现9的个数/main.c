//  04_计算1-100出现9的个数
//  1-100出现9的个数
//  9 19 29 39 49 59 69 79 79
//  90 91 92 93 94 95 96 97 98 99


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    int count = 0;
    for(i=0;i<=100;i++)
    {
        if(i%10 == 9)
        {
            count++;
        }
        if(i/10 == 9)
        {
            count++;
        }
        
    }
    printf("%d\n",count);
    return 0;
}
