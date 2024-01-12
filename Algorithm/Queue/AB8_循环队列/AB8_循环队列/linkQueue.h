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
};

struct Queue *initQueue();
struct Queue *initQueue();
void pushQueue(struct Queue *queue,int data);
void popQueue(struct Queue *queue);
void frontQueue(struct Queue *queue);
void printQueue(struct Queue *queue);



#endif /* linkQueue_h */
