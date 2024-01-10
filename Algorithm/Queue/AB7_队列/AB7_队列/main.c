//  AB7_队列
//  实现一个队列
//  push x:将x加入队尾，x为整数
//  pop:输出队首。并让队首元素出队
//  front:输出队首，队首不出队
//  本次采用链式队列

#include "linkQueue.h"

int main(int argc, const char * argv[])
{
    struct Queue *queue = initQueue();
    char inputOperation[10] = {0};
    int inputData = 0;
    int time = 0;
    scanf("%d",&time);
    while(time)
    {
        scanf("%s",inputOperation);
        if(!strcmp(inputOperation,"push"))
        {
            scanf("%d",&inputData);
            pushQueue(queue, inputData);
        }
        else if(!strcmp(inputOperation,"pop"))
        {
            popQueue(queue);
        }
        else if(!strcmp(inputOperation,"front"))
        {
            frontQueue(queue);
        }
        else
        {
            printf("input command error\n");
        }

        time--;
    }

    return 0;
}
