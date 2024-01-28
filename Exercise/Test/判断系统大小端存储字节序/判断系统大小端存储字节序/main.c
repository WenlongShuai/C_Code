//  main.c
//  判断系统大小端存储字节序
//  判断系统是大端存储字节序还是小端存储字节序
//  大端存储字节序：将数据的高位字节序的内容存储在内存的低地址中，数据的低位字节序的内容存储在内存的高地址中。
//  小端存储字节序：将数据的高位字节序的内容存储在内存的高地址中，数据的低位字节序的内容存储在内存的低地址中。
//  大小端存储字节序只针对字节大于等于2个字节的数据
//  char类型的数据，不存在大小端


#include <stdio.h>

int check_sys()
{
    int a = 1;
    if(*(char*)&a == 1)
        return 1;
    else
        return 0;
}

int main(int argc, const char * argv[])
{
    int ret = check_sys();
    if(ret)
        printf("小端\n");
    else
        printf("大端\n");
    return 0;
}
