//  register关键字

#include <stdio.h>

int main()
{
    register int a = 10;  //register关键字定义的变量会存储在寄存器里。但是能不能存进寄存器得看编译器的处理机制
    a++;
    printf("%d\n",a);
    return 0;
}
