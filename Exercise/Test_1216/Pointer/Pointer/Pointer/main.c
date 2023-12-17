//指针

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int a = 10;   //定义一个int类型的变量
    printf("%d\n",a);
    int *p = &a;  //定义一个指针变量，类型为int *
    printf("%p\n",p);  // %p ---> 打印指针变量的地址
    printf("%d\n",*p);  // 打印指针所指向该地址的值
    *p = 50; //更改指针所指向该地址的值
    printf("%d\n",a);
    
    
    //各种类型指针的字节大小
    //指针变量的字节大小是由计算机的位数决定的
    //如果是x64计算机，则地址是由64bit位组成（8byte），所以指针变量的大小则为8byte。32bit位的计算机同理
    printf("sizeof(char *) = %d\n",sizeof(char *));
    printf("sizeof(short *) = %d\n",sizeof(short *));
    printf("sizeof(int *) = %d\n",sizeof(int *));
    printf("sizeof(float *) = %d\n",sizeof(float *));
    printf("sizeof(double *) = %d\n",sizeof(double *));
    printf("sizeof(long *) = %d\n",sizeof(long *));
    
    return 0;
}
