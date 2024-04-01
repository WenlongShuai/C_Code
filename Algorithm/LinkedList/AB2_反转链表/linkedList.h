//  linkedList.h


#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node* insertLikedList(struct Node *pHead, int num);
void printLinkedList(struct Node *pHead);
struct Node* reversedLinkedList(struct Node* pHead);


#endif /* linkedList_h */
