//  AB5_点击消除
//  输入：abbc     输出：ac
//  输入：bbbbb    输出：b
//  输入：abba     输出：0


#include <stdio.h>
#include <string.h>
#include "stackCreate.h"


int main(int argc, const char * argv[])
{
    char str[300000] = {0};   //输入的字符串
    int i = 1;
    int ret = 0;
    int j = 0;
    int x = 0;
    gets(str);
    int strSize = strlen(str);
    char surplus[300000] = {0};
    char convert[300000] = {0};
    struct HeadNode* T = StackInit();
    PushOperation(T, (int)str[0]);
    while(i < strSize)
    {
        if((int)str[i] == TopOperation(T))
        {
            PopOperation(T);
        }
        else
        {
            PushOperation(T, (int)str[i]);
        }
        i++;
    }
    if(Empty(T))
    {
        printf("0\n");
    }
    else
    {
        while(!Empty(T))
        {
            ret = TopOperation(T);
            surplus[j] = ret;
            PopOperation(T);
            j++;
        }
        for(x = 0;x < j;x++)
        {
            convert[x] = surplus[j-x-1];
        }
        printf("%s\n",convert);
    }
    
    return 0;
}
