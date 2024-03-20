//  06_atoi库函数实现
// 库函数atoi原型：int atoi(const char *nptr)
// 将字符串转换为整数，如果成功转换返回转换后的整数，否则返回0（字符串里面有超过整形数据类型范围的或者字符串为空）


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int myAtoi(const char *nptr)
{
    int ret = 0;
    char symbol = 0;
    
    if(nptr == NULL)
    {
        return 0;
    }
    
    while(*nptr != '\0')
    {
        if(*nptr == ' ')
        {
            nptr++;
            continue;
        }
        
        if(*nptr == '+' || *nptr == '-')
        {
            symbol = *nptr;
        }
        else if(*nptr >= '0' && *nptr <= '9')
        {
            ret = ret * pow(10, 1)+(*nptr-'0');
        }
        else
            break;
        
        if(ret > 32767 || ret < -32767)
        {
            return 0;
        }
        nptr++;
    }
    if('-' == symbol)
        return -ret;
    return ret;
    
}

int main(int argc, const char * argv[])
{
    char arr[20] = {0};
    
    scanf("%s",arr);
    
    int ret = myAtoi(arr);
//    int ret = atoi(arr);
    
    printf("%d\n",ret);

    return 0;
}
