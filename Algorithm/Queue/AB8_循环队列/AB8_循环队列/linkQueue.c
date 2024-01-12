//  linkQueue.c
#include "linkQueue.h"

struct Queue *initQueue()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    node->next = NULL;
    queue->front = node;
    queue->rear = node;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    if(queue->front->next == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *queue)
{
    if(queue->front == queue->rear )
    {
        return 1;
    }
    return 0;
}

void pushQueue(struct Queue *queue,int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(isFull(queue))
    {
        printf("full\n");
        return;
    }
    if(isEmpty(queue))
    {
        newNode->data = data;
        queue->rear = newNode;
        newNode->next = queue->front->next;
        queue->front->next = newNode;
    }
    else
    {
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
        queue->rear = newNode;
        newNode->data = data;
    }
}

void popQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node = queue->front->next;
    queue->front->next = node->next;
    printf("%d\n",node->data);
    free(node);    
}

void frontQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    struct Node *node = queue->front;
    printf("%d\n",node->next->data);
}

void printQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    struct Node *temp = queue->front;
    while(temp->next != NULL)
    {
        printf("%d\n",temp->next->data);
        temp = temp->next;
    }
}

