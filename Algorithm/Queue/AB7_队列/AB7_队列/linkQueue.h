//  linkQueue.h


#ifndef linkQueue_h
#define linkQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct Queue *initQueue();
void pushQueue(struct Queue *queue,int data);
void popQueue(struct Queue *queue);
void frontQueue(struct Queue *queue);
void printQueue(struct Queue *queue);

#endif /* linkQueue_h */
