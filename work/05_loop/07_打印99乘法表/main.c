//
//  main.c
//  07_打印99乘法表
//
//  Created by mac on 2024/1/3.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    int j = 0;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%d\t",j,i,i*j);
        }
        printf("\n");
    }
    return 0;
}
