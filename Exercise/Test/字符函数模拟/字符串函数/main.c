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

//strcpy() strcat() strcmp()这几个都是长度不受限制的字符串函数


//5、将一个字符串按指定的长度复制给另一个字符串
//库函数：char * strncpy ( char * destination, const char * source, size_t num );
//注意事项
//1、目标字符串足够大
//2、如果需要复制的字符num的个数大于源字符串的话，剩余的字符则用'\0'代替。复制给目标字符串中
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

//6、将一个字符串按指定的长度追加到另一个字符串后面
//库函数：char * strncat ( char * destination, const char * source, size_t num );
//注意事项
//1、目标字符串空间足够大
//2、如果需要追加的字符num的个数大于源字符串的话，剩余的字符则不管。就把该有的字符追加到目标字符串'\0'后面就行了
//模拟
char *my_strncat(char *destnation, const char *source, int num)
{
    char *dest = destnation;
    while(*destnation++);
    destnation--;
    while(num--)
    {
        *destnation++ = *source++;
    }
    
    return dest;
}

//7、比较两个字符串中指定长度的大小
//库函数：int strncmp ( const char * str1, const char * str2, size_t num );
//模拟
int my_strncmp(const char *str1,const char *str2,int num)
{
    while(num--)
    {
        if(((*str1==*str2) && (*str1 == '\0')) || *str1!=*str2)
            break;

        str1++;
        str2++;
    }
    return *str1-*str2;
}

//strncpy() strncat() strncmp()这几个都是长度受限制的字符串函数

//8、在字符串中查找子字符串
//库函数：const char * strstr ( const char * str1, const char * str2 );
//       char * strstr (char * str1, const char * str2 );
//模拟
//char *my_strstr(char *str1, const char *str2)
//{
//    assert(str1 && str2);
//    char *s1 = str1;
//    char *s2 = str2;
//
//    while(*s1 != '\0')
//    {
//        if(*s1 == *s2)
//        {
//            s1++;
//            s2++;
//        }
//        else if(*s2 == '\0')
//        {
//            return str1;
//        }
//        else
//        {
//            s1++;
//            str1++;
//        }
//    }
//
//    return NULL;
//}
char *my_strstr(char *str1, const char *str2)
{
    assert(str1 && str2);
    char *s1 = str1;
    char *s2 = str2;
    char *p = str1;
    
    while(*s1 != '\0')
    {
        s1 = p;
        s2 = str2;
        
        while(*s1!='\0' && *s2!='\0' && *s1==*s2)
        {
            s1++;
            s2++;
        }
        
        if(*s2 == '\0')
            return p;
        p++;
    }
    
    return NULL;
}

//9、分割字符串
//库函数：char * strtok ( char * str, const char * delimiters );
//模拟
char *my_strtok( char *str, const char *delimiters)
{
    assert(delimiters);
    char *de = delimiters;
    char *flag = NULL;
    static char *p;
    if(str != NULL)
        p = str;
    flag = p;
    if(*p == '\0')
        return NULL;
        
    while(*p != '\0')
    {
        while(*de != '\0')
        {
            if(*p == *de)
            {
                *p = '\0';
                p++;
                return flag;
            }
            de++;
        }
        de = delimiters;
        p++;
    }
    return flag;
}

//内存函数
//10、内存拷贝函数，只适用于两块独立的内存块拷贝，不能使用内存重叠的拷贝
//库函数：void * memcpy ( void * destination, const void * source, size_t num );
//注意事项：
//1、void *destnation参数为什么是void *
//   因为这个拷贝不仅仅是针对字符串操作，而是针对所有数据类型操作。所以不知道用户会对什么数据进行拷贝
//2、返回值类型为什么是 void *
//   因为不知道对什么数据类型拷贝，所以就不确定返回什么具体的数据类型
//模拟
void *my_memcpy(void *destnation, const void *source, int num)
{
    assert(source);
    char *de = (char *)destnation;
    char *so = (char *)source;
    while(num--)
    {
        *de = *so;
        de++;
        so++;
        
    }
    return destnation;
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
    
    //6、my_strncat()
//    char str1[20] = "abcde\0xxxxxxxx";
//    char str2[] = "hello";
//    char *ret = my_strncat(str1, str2, 8);
//    printf("%s\n",ret);
    
    //7、my_strncmp()
//    char str1[] = "abcde";
//    char str2[] = "abcdf";
//    int ret = my_strncmp(str1, str2, 8);
//    printf("%d\n",ret);
    
    //8、my_strstr()
//    char str1[] = "abbbced";
//    char str2[] = "bc";
//    char *ret = my_strstr(str1, str2);
//    printf("%s\n",ret);
    
    //9、my_strtok()
//    char str1[] = "296@qq.com_qwer";
//    char str2[] = "_.@";
//    char *ret = NULL;
//    ret = my_strtok(str1, str2);
//    while(ret != NULL)
//    {
//        printf("%s\n",ret);
//        ret = my_strtok(NULL, str2);
//    }
    
    //10、my_memcpy()
//    int str1[5] = {1,2,3,4,5};
//    int str2[3] = {0};
//    my_memcpy(str2, str1, 12);
//    int i = 0;
//    for(i=0;i<3;i++)
//    {
//        printf("%d ",str2[i]);
//    }
    
    char str1[] = "hello world";
    char str2[20] = {0};
    char *ret = my_memcpy(str2, str1, 7);
    printf("%s\n",ret);
    
    
    
    
    return 0;
}
