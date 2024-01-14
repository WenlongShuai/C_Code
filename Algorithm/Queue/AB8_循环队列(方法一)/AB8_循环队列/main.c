//  AB8_循环队列
//  实现一个循环队列，该循环队列的空间大小等于n个整型变量的大小
//  操作
//  push x:将x加入到循环队列尾端。若循环队列已满，输出"full"(不含引号)，否则不输出任何内容。保证x为int型整数。
//  front：输出队首元素，队首不出队。若队列为空，输出"empty"(不含引号)。
//  pop：输出队首元素，且队首出队。若队列为空，输出"empty"(不含引号)。
//  第一行输入两个整数n,q(1≤n,q≤10^5)，表示循环队列可利用的空间大小和操作次数。
//  接下来的q行，每行一个字符串，表示一个操作。保证操作是题目描述中的一种。
//  输入
//  3 10
//  push 1
//  push 2
//  front
//  push 3
//  push 4
//  pop
//  pop
//  pop
//  front
//  pop
//  输出
//  1
//  full
//  1
//  2
//  3
//  empty
//  empty



#include <stdio.h>
#include "linkQueue.h"

int main(int argc, const char * argv[])
{
    int queueSize = 0;
    int time = 0;
    char opration[20] = {0};
    int num = 0;
    int n = 0;
    struct Queue *queue = initQueue();
    
    scanf("%d %d",&queueSize,&time);

    while(time)
    {
        scanf("%s",opration);
        if(!strcmp(opration, "push"))
        {
            scanf("%d",&num);
            pushQueue(queue,num);
            if(n == queueSize)
            {
                queue->rear->next = queue->front;
            }
            n++;
        }
        else if(!strcmp(opration, "pop"))
        {
            popQueue(queue);
            n--;
        }
        else if(!strcmp(opration, "front"))
        {
            frontQueue(queue);
        }
        else
        {
            printf("input operation error\n");
            break;
        }
        time--;
    }


    return 0;
}
