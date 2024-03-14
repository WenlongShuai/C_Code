//  main.c
//  求两个数的最小公倍数
//  输入：5 7
//  输出：35
//       6 8
//       24

#include <stdio.h>
#include <math.h>

unsigned int getGCD(int num1,int num2)   //得到最大公因数
{
    unsigned int c = 0;
    while(num1%num2)
    {
        c = num1 % num2;
        num1 = num2;
        num2 = c;
    }
    return num2;
}

//    方法一
//long getLCM(long num1,long num2)   //得到最小公倍数
//{
//    long count = 1;
//    long i = 2;
//    while(1)
//    {
//        if((num1%i!=0) || (num2%i!=0))
//        {
//            i++;
//        }
//        if((num1%i==0) && (num2%i==0))
//        {
//            count *= i;
//            num1 /= i;
//            num2 /= i;
//        }
//        if(getGCD(num1,num2) == 1)
//        {
//            break;
//        }
//    }
//    return num1 * num2 * count;
//}


//  方法二
//long getLCM(long num1,long num2)
//{
//    long lcm = (num1>num2)?num1:num2;
//    while(1)
//    {
//        if((lcm%num1==0) && (lcm%num2==0))
//        {
//            break;
//        }
//        lcm++;
//    }
//    return lcm;
//}


//方法三
// long getLCM(long num1,long num2)
// {
//     int i = 1;
//     while(1)
//     {
//         if((num1*i)%num2 == 0)
//         {
//             break;
//         }
//         i++;
//     }
//     return num1*i;
// }

// 方法四
//最小公倍数 = 两数乘积/最大公约数
long getLCM(long num1,long num2)
{
    return num1*num2/getGCD(num1,num2); 
}

int main(int argc, const char * argv[])
{
    //方法二
//    unsigned int num1 = 0;
//    unsigned int num2 = 0;
//    long result = 0;
//    scanf("%d%d",&num1,&num2);
//    result = getLCM(num1,num2);
//    printf("%ld\n",result);

    //方法一
//    unsigned int num1 = 0;
//    unsigned int num2 = 0;
//    long result = 0;
//    scanf("%d%d",&num1,&num2);
//    result = getLCM(num1,num2);
//    printf("%ld\n",result);
    
    //方法三
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    long result = 0;
    scanf("%d%d",&num1,&num2);
    result = getLCM(num1,num2);
    printf("%ld\n",result);

    return 0;
}
