//  03_小乐乐改数字
//  一串数字，如果某一位的数字是奇数则就把它改为1，偶数改为0
// 输入：123
// 输出：101
// 输入：22222
// 输出：0


#include <stdio.h>
#include <math.h>

int changeTheNumber(int num)
{
    int numBit = 0;
    int count = 0;
    int changeNumAfter = 0;
    while(num)
    {
        numBit = num % 10;
        if(numBit%2 == 0)
        {
            numBit = 0;
        }
        else
        {
            numBit = 1;
        }
        changeNumAfter += numBit * pow(10, count);
        count++;
        num /= 10;
    }
    return changeNumAfter;
}

int main(int argc, const char * argv[])
{
    int num = 0;
    scanf("%d",&num);
    int ret = changeTheNumber(num);
    printf("%d\n",ret);
    return 0;
}
