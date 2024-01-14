//  linkQueue.c

//  不需要头节点
#include "linkQueue.h"

struct Queue *initQueue(int queueSize)
{
    int numNode = queueSize+1;
    struct Node *top = NULL;
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->size = 0;
    while(numNode)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        if(numNode == queueSize+1)
        {
            node->next = NULL;
            queue->front = node;
            queue->rear = node;
            top = node;
        }
        else
        {
            top->next = node;
            top = node;
        }
        numNode--;
    }
    top->next = queue->front;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    if(queue->rear == queue->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *queue)
{
    if(queue->rear->next == queue->front)
    {
        return 1;
    }
    return 0;
}

void pushQueue(struct Queue *queue,int data)
{
    if(isFull(queue))
    {
        printf("full\n");
        return;
    }
    queue->rear->data = data;
    queue->rear = queue->rear->next;
    queue->size++;
}

void popQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    printf("%d\n",queue->front->data);
    queue->front->data = 0;
    queue->front = queue->front->next;
    queue->size--;
}

void frontQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    printf("%d\n",queue->front->data);
}

void printQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    struct Node *temp = queue->front;
    while(temp->next != queue->front)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void freeQueue(struct Queue *queue)
{
    struct Node *endNode = (struct Node *)malloc(sizeof(struct Node));
    endNode = queue->front;
    queue->front = queue->front->next;
    while(queue->front != endNode)
    {
        struct Node *temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
    }
    free(endNode);
    free(queue);
}
