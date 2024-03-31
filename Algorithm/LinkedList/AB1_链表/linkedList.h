//  linkedList.h


#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


struct Node* linkedListInit();
void linkedListPush(struct Node *headNode, int num, insertNum);
void linkedListPop(struct Node *headNode, int num);
void linkedListPrint(struct Node *headNode);


#endif /* linkedList_h */
