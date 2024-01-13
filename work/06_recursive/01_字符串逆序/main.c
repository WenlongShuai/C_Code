//  01_字符串逆序
//  将字符串逆序打印，不能使用C库函数
//  “abcdef”--->"fedcba"


#include <stdio.h>
#include <string.h>

int my_strlen(char *str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

//方法一，使用固定的函数，函数的返回值以及参数个数类型都被限定
//void reverseString(char *s)
//{
//    int len = my_strlen(s);
//    char tmp = *s;  //1、取出字符串的第一个元素，并放在中间变量里
//    *s = *(s+len-1); //2、将字符串最后一个元素放在字符串中第一个元素的位置，实现交换位置
//    *(s+len-1) = '\0';  //3、将字符串中的最后一个元素置为'\0'，然后作为新的字符串
//    if(my_strlen(s+1) >=2)  //字符串的个数必须在2个以上才继续递归
//    {
//        reverseString(s+1); //4、将新的字符串作为参数继续递归
//    }
//    *(s+len-1) = tmp;  //5、将之前取出字符串的第一个元素放在之前字符串中最后一个置为'\0'的位置
//}

//方法二，没有任何限制，参数个数自己决定
void reverseString2(char *s,int left,int right)
{
//    char tmp = *(s+left);
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    left++;
    right--;
    if(left < right)
    {
        reverseString2(s, left, right);
    }
}

//这个跟reverseString2函数的差别就是当两字符换完位置之后，比较left、right，比较完了再对left、right进行操作。导致当字符串字符的个数为偶数时就会出错
//void reverseString3(char *s,int left,int right)
//{
////    char tmp = *(s+left);
//    char tmp = s[left];
//    s[left] = s[right];
//    s[right] = tmp;
//    if(left < right)
//    {
//        reverseString2(s, left+1, right-1);
//    }
//}

//改正之后：
void reverseString3(char *s,int left,int right)
{
//    char tmp = *(s+left);
    if(left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        reverseString2(s, left+1, right-1);
    }
}


int main(int argc, const char * argv[])
{
    //方法一的使用
//    char str[] = "qwer";
//    reverseString(str);
//    printf("%s\n",str);
    
    //方法二的使用
    char str[] = "abcdefg";
    int left = 0;
    int right = strlen(str)-1;
    reverseString3(str,left,right);
    printf("%s\n",str);

    return 0;
}
