//typedef关键字 ------- 类型重命名

#include <stdio.h>

//将 unsigned int 数据类型重新命名为 uint_1   typedef在编译阶段执行
typedef unsigned int uint_1;

//将 struct Node 结构体自定义数据类型重新命名为 node
typedef struct Node
{
    int data;
    struct Node *next;
    
}node;

int main(int argc, const char * argv[])
{
    uint_1 a = 100;
    node n1;
    printf("%d\n",a);
    return 0;
}
