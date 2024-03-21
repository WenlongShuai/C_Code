//  07_offsetof宏的实现
//  实现offsetof宏
//  计算一个结构体变量与结构体首地址的偏移量


#include <stdio.h>

#define OFFSETOF(type, name) (int)(&((type*)0)->name)


struct Per
{
    int a;
    char b;
    int c;
    double d;
};

int main(int argc, const char * argv[])
{
    printf("%d\n",OFFSETOF(struct Per, d));
    return 0;
}
