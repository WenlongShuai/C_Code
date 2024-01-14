//  linkQueue.h

#ifndef linkQueue_h
#define linkQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front; //队头指针
    struct Node *rear;  //队尾指针
    int size;   //记录链表队列的个数
};

struct Queue *initQueue(int queueSize);
void pushQueue(struct Queue *queue,int data);
void popQueue(struct Queue *queue);
void frontQueue(struct Queue *queue);
void printQueue(struct Queue *queue);
int isEmpty(struct Queue *queue);
void freeQueue(struct Queue *queue);



#endif /* linkQueue_h */
