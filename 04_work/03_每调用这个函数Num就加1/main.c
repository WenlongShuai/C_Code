//  03_每调用这个函数Num就加1


#include <stdio.h>

void addNum(int *num)
{
    (*num)++;
}

int main(int argc, const char * argv[])
{
    
    int num = 0;
    addNum(&num);
    addNum(&num);
    addNum(&num);
    addNum(&num);
    printf("%d\n",num);
    return 0;
}
