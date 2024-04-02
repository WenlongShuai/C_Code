//  linkedList.h

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



struct Node
{
    int data;
    struct Node *next;
};


struct Node* insertLinkedList(struct Node *pHead, int num);
struct Node* merge(struct Node *pHead1,struct Node *pHead2);
void printLinkedList(struct Node *pHead);

#endif /* linkedList_h */
