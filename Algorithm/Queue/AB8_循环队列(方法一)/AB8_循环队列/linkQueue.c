//  linkQueue.c
#include "linkQueue.h"

struct Queue *initQueue()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if(node==NULL || queue==NULL)
    {
        printf("%s\n",strerror(errno));
        return NULL;
    }
    node->next = NULL;
    queue->front = node;
    queue->rear = queue->front;
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }
    if(isEmpty(queue))
    {
        newNode->data = data;
        newNode->next = queue->front->next;
        queue->front->next = newNode;
        queue->rear = newNode;
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
    if(node==NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }
    node = queue->front->next;
    queue->front->next = node->next;
//    if(node->next == queue->front)
//    {
//        queue->rear = node->next;
//    }
    printf("%d\n",node->data);
    free(node);  //因为free掉了这块内存之后，node指针指向的地址还是原来那块内存。这样node就会成为野指针。所以释放完了，要将node指向的地址置为NULL。
    node = NULL;
}

void frontQueue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("empty\n");
        return;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node==NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }
    node = queue->front->next;
    printf("%d\n",node->data);
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
//
//3 10
//push 1
//push 2
//front
//push 3
//push 4
//pop
//pop
//pop
//front
//pop
