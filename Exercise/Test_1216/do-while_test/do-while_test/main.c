//  do-while_test
//do
//{
//    //循环体
//}while(条件判断);
//跟while循环差别就是，while会先判断在执行循环体，而do-while则会先执行一遍循环体再去判断条件是否成立

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i = 0;
    do
    {
        if(i == 5)
        {
           continue;
        }
        printf("%d ",i);
        i++;
    } while (i <= 10);
    
    return 0;
}
