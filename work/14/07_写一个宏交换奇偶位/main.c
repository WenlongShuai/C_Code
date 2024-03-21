//  07_写一个宏交换奇偶位
//  写一个宏交换一个数的二进制的奇偶位
// 1001 ---> 0110

#include <stdio.h>

#define SWAP_BIT(n) (((n & 0x5555555555555555)<<1)+((n & 0xaaaaaaaaaaaaaaaa)>>1))

int main(int argc, const char * argv[])
{
//    int n = 7;
//    int odd = 0;
//    int even = 0;
//    int i = 0;
//    int j = 0;
//    for(i=0;i<32;i++)
//    {
//        if(0 == i%2)
//        {
//            even = (even<<j) | (n & (1<<i));
//            printf("%d\n",even);
//        }
//        else
//        {
//            odd = (odd<<j) | (n & (1<<i));
//            printf("%d\n",odd);
//        }
//        j++;
//    }
//
//    printf("%d %d",even,odd);
    
    
    int n = 0;
    scanf("%d",&n);
    
    printf("%d\n",SWAP_BIT(n));
    
    return 0;
}
