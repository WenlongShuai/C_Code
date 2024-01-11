//  BC9_PrintfReturnValue
//  输出printf的返回值


#include <stdio.h>

int main(int argc, const char * argv[])
{
    //方法一
//    int returnValue = printf("Hello, World!\n");
//    printf("%d\n",returnValue);
    
    //方法二
    printf("%d\n",printf("Hello, World!\n"));
    return 0;
}
