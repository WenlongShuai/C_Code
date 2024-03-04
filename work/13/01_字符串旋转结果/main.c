//  01_字符串旋转结果
//  判断一个字符串是否为另一个字符串旋转之后的结果
//  s1="ABCD"  s2="BCDA"  输出：1
//  s1="abcd"  s2="ACBD"  输出：0

#include <stdio.h>
#include <string.h>

void reverseString(char *str, int left, int right)
{
    char tmp = 0;
    while(left < right)
    {
        tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        
        left++;
        right--;
    }
}

int judgeStringRotate(char *str1, char *str2)
{
    
    int str1Len = strlen(str1);
    int count = str1Len;
    while(count)
    {
        //因为判断相等，需要每次旋转一个字符，旋转一次判断一次，直到旋转到原字符串之后就停止
        reverseString(str1,0,0);     //取出字符串中的第一个字符进行逆序
        reverseString(str1,1,str1Len-1);  //取出第一个字符后面的字符串逆序
        reverseString(str1, 0, str1Len-1);  //最后将整个字符串逆序
        
        if(!strcmp(str1,str2))
            return 1;
        count--;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    char s1[] = "AABCD";
    char s2[] = "BCDAA";  //DAABC
    
    int ret = judgeStringRotate(s1, s2);
    
    printf("%d\n",ret);
    
    return 0;
}
