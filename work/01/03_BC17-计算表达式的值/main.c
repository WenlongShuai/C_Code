//
//  main.c
//  03_BC17-计算表达式的值
//
//  Created by mac on 2023/12/13.
//

#include <stdio.h>

int Eval(int a,int c)
{
    return (-8+22)*a-10+c/2;
}

int main(int argc, const char * argv[]) {
    //(-8+22)*a-10+c/2   a=40,c=212
    int a = 40;
    int b = 212;
    int result = Eval(a, b);
    printf("%d\n",result);
    
    return 0;
}
