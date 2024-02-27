//
//  main.c
//  字符串函数
//模拟字符串库函数

#include <stdio.h>
#include <assert.h>
#include <string.h>

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


//4、比较两个字符串的大小
//库函数：int strcmp ( const char * str1, const char * str2 )
//模拟
int my_strcmp(const char *str1,const char *str2)
{
    assert(str1 && str2);
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
//    if(*str1 > *str2)
//        return 1;
//    else
//        return -1;
    return *str1-*str2;
}
//前面的几个库函数的长度不受限制


//5、将一个字符串按指定的长度复制给另一个字符串
//库函数：char * strncpy ( char * destination, const char * source, size_t num );
//注意事项
//1、目标字符串足够大
//2、如果需要复制的字符的个数大于源字符串的话，剩余的字符则用'\0'代替。复制给目标字符串中
//模拟
char *my_strncpy(char *destnation, const char *source, int num)
{
    char *dest = destnation;
    while(num--)
    {
        *destnation++ = *source++;
    }
    return dest;
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
//    char dest[20] = "hello ";
//    char *source = "world";
//    char *ret = my_strcat(dest, source);
//    printf("%s\n",ret);
    
    //4、my_strcmp()
//    char str1[] = "abcdef";
//    char str2[] = "abcdegb";
//    int ret = my_strcmp(str1, str2);
//    if(ret == 0)
//        printf("==\n");
//    else if(ret < 0)
//        printf("<\n");
//    else
//        printf(">\n");
    
    //5、my_strncpy()
//    char str1[] = "hello 12345";
//    char str2[] = "world";
//    char *ret = my_strncpy(str1, str2, 7);
//    printf("%s\n",ret);
    
        
    
    
    return 0;
}
