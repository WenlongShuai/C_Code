//
//  main.c
//  05_判断是不是字母
//  输入：A
//  输出：is an alphabet
//  输入：6
//  输出：is not an alphabet
#include <stdio.h>

int main(int argc, const char * argv[])
{
    char ch = 0;
    while(scanf("%c",&ch) == 1)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            printf("is an alphabet\n");
        }
        else
        {
            printf("is not an alphabet\n");
        }
        getchar();
    }
    
    return 0;
}
