//  10_替换字符串中的空格
//
//描述：请实现一个函数，将一个字符串s中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。保证字符串中的字符为大写英文字母、小写英文字母和空格中的一种。
//
//示例1
//输入："We Are Happy"
//返回值："We%20Are%20Happy"
//
//示例2
//输入：" "
//返回值："%20"


#include <stdio.h>
#include <string.h>

//方法一
//需要重新创建一个数组，然后读取原数组的值，如果遇到空格就在增加“%20”三个字符到新数组中，如果没有遇到，就把原数组元素写到新数组里
//这样就很浪费空间
void replaceSpace1(char *str)
{
    char newStr[100] = {0};
    int i = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
        {
            newStr[i] = '%';
            i++;
            newStr[i] = '2';
            i++;
            newStr[i] = '0';
            i++;
        }
        else
        {
            newStr[i] = *str;
            i++;
        }
        str++;
    }
    
    printf("%s\n",newStr);
}

//方法二
//在原数组的基础上添加“%20”
//首先计算数组中的空格有几个，然后每个空格需要更改为“%20”三个字符，字符串的长度也要增加
//定义两个变量end1,end2，end1指向没有增加字符“%20”前的末尾，end2指向假如增加字符“%20”之后的数组末尾
//end1就往前找，如果不是空格，那么end2也往前移动一个字符，否则就往前移动3个字符

void replaceSpace2(char *str)
{
    int spaceCount = 0;
    char *cur = str;
    int len = strlen(str);
    
    //找空格的个数
    while(*cur != '\0')
    {
        if(' ' == *cur)
        {
            spaceCount++;
        }
        cur++;
    }
    
    int end1 = len-1;
    int end2 = len+spaceCount*2-1;
    
    while(end1 != end2)
    {
        if(' ' != str[end1])
        {
            str[end2--] = str[end1--];
        }
        else
        {
            end1--;
            str[end2--] = '0';
            str[end2--] = '2';
            str[end2--] = '%';
        }
    }
    
    
}

int main(int argc, const char * argv[])
{
    //方法一
    char arr[100] = {0};
    fgets(arr, 100, stdin);
    replaceSpace1(arr);
    
    //方法二
//    char arr[100] = {0};
//    fgets(arr, 100, stdin);
//    replaceSpace2(arr);
//    printf("%s\n",arr);
    
    return 0;
}
