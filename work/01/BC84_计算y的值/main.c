//
//  main.c
//  BC84_计算y的值
//
//  Created by mac on 2023/12/14.
//

#include <stdio.h>

int calculateY(int x)
{
    if(x < 0)
    {
        return 1;
    }
    else if(x == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    int inputNum;
    scanf("%d",&inputNum);
    int y = calculateY(inputNum);
    printf("%d\n",y);
    return 0;
}
