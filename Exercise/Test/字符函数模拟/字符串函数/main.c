//
//  main.c
//  字符串函数
//模拟字符串库函数

#include <stdio.h>
#include <assert.h>

//1、求字符串长度
//库函数：size_t strlen(const char *str)
//模拟求字符串长度
int my_strlen(const char* str)
{
    assert(str);
    int count = 0;
    while(*str)
    {
        str++;
        count++;
    }
    return count;
}


//2、将一个字符串复制到另一个字符串
//库函数：char *strcpy(char *destnation,const char *source)
//注意事项：
//1、源字符串必须以'\0'结尾
//2、目标字符串的空间足够大，防止越界
//3、源字符串的'\0'也会被复制到目标字符串中
//4、目标字符串必须是可以修改的
//模拟
char *my_strcpy(char *destnation,const char *source)
{
    assert(destnation);
    assert(source);
    char *ret = destnation;
//    while(*destnation = *source)
//    {
//        destnation++;
//        source++;
//    }
    while(*destnation++ = *source++);   //后置++优先级高于*
    
    return ret;
}

//3、在一个字符串后面追加一个字符串
//库函数：char *strcat(char *destnation,const char *source)
//注意事项：
//1、源字符串必须以'\0'结尾
//2、目标字符串的空间足够大，防止越界
//3、源字符串的'\0'也会被复制到目标字符串中
//4、目标字符串必须是可以修改的
//模拟
char *my_strcat(char *destnation,const char *source)
{
    assert(destnation);
    assert(source);
    char *ret = destnation;
    while(*destnation++);  //找到目标字符串最后一个字符的位置
    destnation--;
    while(*destnation++ = *source++);
    return ret;
}

int main(int argc, const char * argv[])
{
    //1、my_strlen()
//    char arr[10] = "abcde12";
//    int sz = my_strlen(arr);
//    printf("%d\n",sz);
    
    //2、my_strcpy()
//    char dest[20] = {0};
//    char *source = "hello world123";
//    char *ret = my_strcpy(dest, source);
//    printf("%s\n",ret);
    
    //3、my_strcat()
    char dest[20] = "hello ";
    char *source = "world";
    char *ret = my_strcat(dest, source);
    printf("%s\n",ret);
    return 0;
}

