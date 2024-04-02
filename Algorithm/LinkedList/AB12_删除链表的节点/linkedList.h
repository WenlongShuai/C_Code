//  linkedList.h


#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node *next;
};



struct Node* insertLikedList(struct Node *pHead, int num);
void printLinkedList(struct Node *pHead);
struct Node *deleteLinkedListNode(struct Node *head, int num);


#endif /* linkedList_h */
