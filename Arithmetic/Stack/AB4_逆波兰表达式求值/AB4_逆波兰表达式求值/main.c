//  AB4_逆波兰表达式求值
//  输入：["2","1","+","4","*"]   输出：12
//  输入：["2","0","+"]   输出：2

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stackCreate.h"



int StringToNum(char *str)
{
    int strSize = strlen(str);
    int ret = 0;
    int i = 0;
    if(str == NULL)
    {
        return -1;
    }
    
    if((strSize > 1) && (str[0] == '-'))
    {
        while(str[i] != '\0')
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                ret += (str[i] - '0') * (int)pow(10, strSize-i-1);
            }
            i++;
        }
        ret = -ret;
        
    }
    else
    {
        while(str[i] != '\0' )
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                ret += (str[i] - '0') * (int)pow(10, strSize-i-1);
            }
            else
            {
                ret = (int)(str[i]);
            }
            i++;
        }
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    struct HeadNode *T = StackInit();
    char tokens[][10] = {"3","-19","-","13","33","+","-","-1","-"};
    int x = 0;
    int y = 0;
    char symbol = '0';
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int i = 0;
    int result = 0;
    
    while(i < tokensSize)
    {
        PushOperation(T,StringToNum(tokens[i]));
        if(TopOperation(T) == '+' || TopOperation(T) == '-' || TopOperation(T) == '*' || TopOperation(T) == '/')
        {
            symbol = TopOperation(T);
            PopOperation(T);
            x = TopOperation(T);
            PopOperation(T);
            y = TopOperation(T);
            PopOperation(T);
            if(symbol == '+')
            {
                result = y + x;
            }
            else if(symbol == '-')
            {
                result = y - x;
            }
            else if(symbol == '*')
            {
                result = y * x;
            }
            else
            {
                if(x != 0)
                {
                    result = y / x;
                    
                }
            }
            PushOperation(T, result);
        }
        result = TopOperation(T);
        i++;
    }
    
    printf("%d\n",result);
   
    return 0;
}
