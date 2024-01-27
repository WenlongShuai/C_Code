//  main.c
//  倒置字符串
//  输入：I like beijing.
//  输出：beijing. like I

//  方法一
//  运行时间：2ms。占用内存：340KB
//  1、先将字符串以空格分割，得到每个单词
//  2、将每个单词存放在二维数组中
//  3、创建一个二维数组副本
//  4、将二维数组里面的一维数组元素倒置放在二维数组副本里
//  5、将二维数组副本的每个元素依次取出放入形参的一维数组里面

//#include <stdio.h>
//#include <string.h>
//void inversionString(char *str)
//{
//    char pointArr[100][100] = {0};
//    char tmp[100][100] = {0};
//    int i = 0;
//    int j = 0;
//    int count = 0;
//    char *strTmp = str;
//    char *start = str;
//    char *end = 0;
//
//    //将字符串通过空格分割成多个字符串
//    while(1)
//    {
//        if(*strTmp == ' ')
//        {
//            end = strTmp;
//            for(i=0;i<end-start;i++)
//            {
//                pointArr[j][i] = start[i];
//            }
//            j++;
//            start = end+1;
//        }
//        if(*strTmp == '\0')
//        {
//            end = strTmp;
//            for(i=0;i<end-start;i++)
//            {
//                pointArr[j][i] = start[i];
//            }
//            break;
//        }
//        strTmp++;
//    }
//
//    //将分割的字符串倒置
//    i = 0;
//    while(1)
//    {
//        if(!strcmp(pointArr[i], ""))
//        {
//            break;
//        }
//        i++;
//        count++;
//    }
//    for(i=count-1,j=0;i>=0;i--,j++)
//    {
//        strcpy(tmp[j],pointArr[i]);
//    }
//
//    //将二维数组副本里的元素依次取出放入传进来的一维数组里面
//    i = 0;
//    j = 0;
//    count = 0;
//    while(1)
//    {
//        if(tmp[j][i] == '\0')
//        {
//            str[count] = ' ';
//            j++;
//            i = 0;
//            count++;
//        }
//        else
//        {
//            str[count] = tmp[j][i];
//            i++;
//            count++;
//        }
//
//        if(!strcmp(tmp[j], ""))
//        {
//            break;
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    char str[100] = {0};
//    gets(str);
//
//    inversionString(str);
//
//    printf("%s\n",str);
//
//    return 0;
//}



//  方法二
//  运行时间：3ms   占用内存：284KB
//  1、先将字符串以空格分割，得到每个单词
//  2、将每个单词存放在二维数组中
//  3、创建一个中间指针变量用于交换二维数组中前后两个一维数组元素
//  4、将二维数组的每个元素依次取出放入一维数组里面
//#include <stdio.h>
//#include <string.h>
//void inversionString(char *str)
//{
//    char pointArr[100][100] = {0};
//    char tmp[100] = {0};
//    int i = 0;
//    int j = 0;
//    int count = 0;
//    char *strTmp = str;
//    char *start = str;
//    char *end = 0;
//    int left = 0;
//    int right = 0;
//
//    //将字符串通过空格分割成多个字符串
//    while(1)
//    {
//        if(*strTmp == ' ')
//        {
//            end = strTmp;
//            for(i=0;i<end-start;i++)
//            {
//                pointArr[j][i] = start[i];
//            }
//            j++;
//            start = end+1;
//        }
//        if(*strTmp == '\0')
//        {
//            end = strTmp;
//            for(i=0;i<end-start;i++)
//            {
//                pointArr[j][i] = start[i];
//            }
//            break;
//        }
//        strTmp++;
//    }
//
//    //将二维数组的一维数组前后交换
//    i = 0;
//    while(1)
//    {
//        if(!strcmp(pointArr[i], ""))
//        {
//            break;
//        }
//        i++;
//        right++;
//    }
//    right -= 1;
//
//    while(left<right)
//    {
//        strcpy(tmp,pointArr[right]);
//        strcpy(pointArr[right],pointArr[left]);
//        strcpy(pointArr[left],tmp);
//        left++;
//        right--;
//    }
//
//    //将二维数组副本里的元素依次取出放入传进来的一维数组里面
//    i = 0;
//    j = 0;
//    count = 0;
//    while(1)
//    {
//        if(pointArr[j][i] == '\0')
//        {
//            str[count] = ' ';
//            j++;
//            i = 0;
//            count++;
//        }
//        else
//        {
//            str[count] = pointArr[j][i];
//            i++;
//            count++;
//        }
//        if(!strcmp(pointArr[j], ""))
//        {
//            break;
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    char str[100] = {0};
//    gets(str);
//
//    inversionString(str);
//
//    printf("%s\n",str);
//
//    return 0;
//}


//  方法三
//  运行时间：2ms   占用内存：288KB
//  1、先将整个字符串倒置
//  2、再将每个单词倒置

#include <stdio.h>
#include <string.h>


//将字符串倒置
void reverse(char *left,char *right)
{
    while(left<right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main(int argc, const char * argv[])
{
    char str[100] = {0};
    gets(str);
    int len = strlen(str);
    
    reverse(str,str+len-1);
    
    char *start = str;
    char *end = str;
    
    while(*start != '\0')
    {
        while(*end != ' ' && *end != '\0')
        {
            end++;
        }
        
        reverse(start, end-1);
        
        if(*end != '\0')
            end++;
        start = end;
    }
    printf("%s\n",str);

    return 0;
}

