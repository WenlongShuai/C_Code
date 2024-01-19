//
//  main.c
//  04_字母大小转换
//  有一个字母，判断他是否为大写，如果是大写则转换成小写，如果是小写则转换成大写
//  scanf()读取成功之后返回读取到字符的个数
//  scanf()读取失败之后返回EOF

#include <stdio.h>

int main(int argc, const char * argv[])
{
    char ch = 0;
    
    //  方式一
    while (scanf("%c",&ch) == 1)
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            printf("%c\n",ch+32);
        }
        else
        {
            printf("%c\n",ch-32);
        }

        getchar();
    }
    
    
//
//    //方式二
//    while (scanf("%c",&ch) == 1)
//    {
//        if(ch >= 'A' && ch <= 'Z')
//        {
//            printf("%c\n",ch+32);
//        }
//        else if(ch >= 'a' && ch <= 'z')
//        {
//            printf("%c\n",ch-32);
//        }
//    }
    
    
    
    
    
    return 0;
}
