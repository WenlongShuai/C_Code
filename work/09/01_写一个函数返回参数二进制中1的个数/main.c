//  main.c
//  01_写一个函数返回参数二进制中1的个数

#include <stdio.h>

int binary1Count(int binaryNum)
{
    int i = 0;
    int count = 0;
    for(i=0;i<32;i++)
    {
        if(binaryNum & (1<<i))   //if((binaryNum & (1<<i)) == 1<<i)
        {
            count++;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[])
{
    int num = 127;
    int count = 0;
    count = binary1Count(num);
    printf("%d\n",count);
    return 0;
}
