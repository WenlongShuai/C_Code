//
//  main.c
//  求两个数的最大值
//
//  Created by mac on 2023/12/14.
//

#include <stdio.h>

int CompareMAX(int a,int b);

int main(int argc, const char * argv[])
{
    int a;
    int b;
    scanf("%d %d",&a,&b);
    int result = CompareMAX(a, b);
    printf("%d\n",result);
    return 0;
}


int CompareMAX(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
