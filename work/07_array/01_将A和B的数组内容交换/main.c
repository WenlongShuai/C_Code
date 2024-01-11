//  01_将A和B的数组内容交换
//  交换前
//  char A[5] = {'a','b','c','d','e'}
//  char B[5] = {'1','2','3','4','5'}

//  交换后
//  char A[5] = {'1','2','3','4','5'}
//  char B[5] = {'a','b','c','d','e'}


#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char A[6] = {'a','b','c','d','e'};
    char B[6] = {'1','2','3','4','5'};
    int i = 0;
    char tmp = 0;
    for(i=0;i<strlen(A);i++)
    {
        tmp = A[i];
        A[i] = B[i];
        B[i] = tmp;
    }
    
    printf("交换后：\n");
    printf("A = %s\n",A);
    printf("B = %s\n",B);
    
    return 0;
}
