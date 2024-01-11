//  01_判断一个数是否为素数
//  素数：大于1的自然数中，除去本身和1两个因数，没有其他的因数的自然数


// 简单版 效率低
//#include <stdio.h>
//int main(int argc, const char * argv[])
//{
//    int num = 0;
//    int i = 2;
//    int count = 0;
//    scanf("%d",&num);
//    if(num == 1)
//    {
//        printf("%d\n",num);
//    }
//    else
//    {
//        while(i < num)
//        {
//            if(num % i == 0)
//            {
//                count++;
//                break;
//            }
//            i++;
//        }
//        if(count == 0)
//        {
//            printf("%d\n",num);
//        }
//        else
//        {
//            printf("不是素数\n");
//        }
//    }
//    return 0;
//}

//改进版 效率高
#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0;
    int flag = 1;
    int i = 0;
    scanf("%d",&num);
    for(i = 2;i <= sqrt(num);i++)
    {
        if(num % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        printf("%d\n",num);
    }
    else
    {
        printf("不是素数\n");
    }
    return 0;
}
