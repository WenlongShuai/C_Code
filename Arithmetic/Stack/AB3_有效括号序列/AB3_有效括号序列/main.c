//  AB3_有效括号序列
//  例如：输入"{}[]()"、"{[()]}"，则为有效的括号序列
//      输入"{}[(])"、"{{]]()"，则为无效的括号序列

#include <stdio.h>
#include <string.h>
#include "stackCreate.h"

int main(int argc, const char * argv[])
{
    char bracketArr[] = "(]{}";
    struct HeadNode *T = StackInit();
    
    int sz = strlen(bracketArr);
    int i = 0;
    while(i < sz)
    {
        if((int)bracketArr[i] == (TopOperation(T)+2) || (int)bracketArr[i] == (TopOperation(T)+1))
        {
            PopOperation(T);
        }
        else
        {
            PushOperation(T, (int)bracketArr[i]);
        }
        i++;
    }
    if(Empty(T))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    
    return 0;
}
