//  linkQueue.c

#include "linkQueue.h"

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

//队列初始化
struct Queue *initQueue()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    node->next = NULL;
    queue->front = node;
    queue->rear = node;
    return queue;
}

//判断队列是否为空
int isEmpty(struct Queue *queue)
{
    if((queue->front->next == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//入队
void pushQueue(struct Queue *queue,int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(isEmpty(queue))
    {
        newNode->data = data;
        newNode->next = queue->rear->next;
        queue->front->next = newNode;
        queue->rear = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = queue->rear->next;
        
        //每新增一个元素，就把新元素的地址给上一个元素的next，因为front始终指向头节点，所以这里只对rear操作。插入新元素之前，rear指向队尾元素
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

//输出队首，出队
void popQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("error\n");
    }
    else
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node = queue->front->next;
        queue->front->next = node->next;
        printf("%d\n",node->data);
        free(node);
    }
}

//输出队首，不出队
void frontQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("error\n");
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p = queue->front->next;
        printf("%d\n",p->data);
    }
}

//打印队列里面的元素
void printQueue(struct Queue *queue)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = queue->front->next;
    
    while((temp != NULL))
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
