//  AB2_栈的压入弹出序列
//  两个序列，一个入栈序列，一个出栈序列。
//  判断入栈序列的出栈是否等于出栈序列


#include <stdio.h>
#include <string.h>
#include "stackCreate.h"

//int main()
//{
//    int pushList[5] = {1,2,3,4,5};
//    int popList[5] = {5,4,3,1,2};
//    int i = 0;
//    int j = 0;
//    int flag = 1;
//    struct HeadNode *T = StackInit();
//    int pushSZ = sizeof(pushList)/sizeof(pushList[0]);
//    int popSZ = sizeof(popList)/sizeof(popList[0]);
//    for(i = 0;i < popSZ;i++)
//    {
//        while(j < pushSZ && (!Empty(T) || (TopOperation(T) != popList[i])) )
//        {
//            PushOperation(T, pushList[j]);
//            j++;
//        }
//        if(TopOperation(T) == popList[i])
//        {
//            PopOperation(T);
//        }
//        else
//        {
//            flag = 0;
//            break;
//        }
//    }
//    if(flag)
//    {
//        printf("true\n");
//    }
//    else
//    {
//        printf("false\n");
//    }
//
//    return 0;
//}


int main()
{
    //[1,2,3,4,5],[1,4,2,5,3]
    int pushList[5] = {1,2,3,4,5};
    int popList[5] = {1,4,2,5,3};
    int i = 0;
    int j = 0;
    struct HeadNode *T = StackInit();
    PushOperation(T, pushList[i]);
    
    //这种循环条件会导致当入栈序列和出栈序列的第一个元素相等时，出栈之后，栈内为空，就会跳出循环。就不继续把入栈序列继续入栈
    //while(Empty(T) && j < 5)
    while(!Empty(T) || j < 5)
    {
        //因为我在TopOperation()函数没有进行空栈判断，所以当栈为空时，头节点里面的next指针变量就会指向NULL。
        //在这里如果栈为空，再去执行TopOperation(T)这函数，就会导致堆栈溢出，返回一个NULL->data，所以会导致报错
        //if(TopOperation(T) == popList[j])
        if(Empty(T) && TopOperation(T) == popList[j])
        {
            PopOperation(T);
            j++;
        }
        else
        {
            i++;
            if(Empty(T) && i > 5)
            {
                printf("false\n");
                return 0;
            }
            PushOperation(T, pushList[i]);
        }
    }
    printf("true\n");
    
    return 0;
}

