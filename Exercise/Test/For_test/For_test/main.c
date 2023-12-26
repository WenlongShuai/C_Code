//  For_test
//for(初始化变量;判断条件;变量调整)
//{
//    循环体
//}

#include <stdio.h>
int main(int argc, const char * argv[])
{
    //本次for循环，循环体一次都不执行
    //step1:执行变量初始化（i=0,k=0）
    //step2:执行判断条件（k=0）,此语句为赋值语句，值为0
    //step3:判断语句为假，则循环体不执行
//    int i = 0;
//    int k = 0;
//    for(i = 0,k = 0;k=0;++i,k++)
//    {
//        printf("hello\n");
//    }
    
    
    //continue在不同循环中的使用
    int i = 0;
    int j = 0;
    for(i = 0;i <= 10;i++)
    {
        if(i == 5)
        {
            continue;
        }
        printf("%d ",i);
    }
    while(j <= 10)
    {
        if(j == 5)
        {
            continue;
        }
        printf("%d ",j);
        j++;
    }
    
    return 0;
}
