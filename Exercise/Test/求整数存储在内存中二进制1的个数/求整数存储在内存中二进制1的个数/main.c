//  main.c
//  求整数存储在内存中二进制1的个数

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    int num = 1;
    int count = 0;
//    for(i=0;i<32;i++)
//    {
//        if((num & (1<<i)) == 1<<i)
//        {
//            count++;
//        }
//    }
    
    for(i=0;i<32;i++)
    {
        if((num>>i & 1) == 1)
        {
            count++;
        }
    }
    printf("%d\n",count);
    
    return 0;
}
