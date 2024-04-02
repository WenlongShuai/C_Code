//  linkedList.c

#include "linkedList.h"


struct Node* insertLikedList(struct Node *pHead, int num)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        perror("insertLikedList malloc error\n");
        return NULL;
    }
    
    if(pHead == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = pHead->next;
        pHead->next = newNode;
    }
    newNode->data = num;
    return newNode;
}


void printLinkedList(struct Node *pHead)
{
    if(pHead == NULL)
    {
        printf("{}\n");
        return;
    }
    while(pHead != NULL)
    {
        printf("%d ",pHead->data);
        pHead = pHead->next;
    }
}

struct Node *deleteLinkedListNode(struct Node *head, int num)
{
    assert(head);
    struct Node *pHead = (struct Node*)malloc(sizeof(struct Node));
    pHead->next = head;
    struct Node *lastNode = pHead;
    while(head != NULL)
    {
        if(head->data == num)
        {
            lastNode->next = head->next;
            free(head);
            head = NULL;
            break;
        }
        lastNode = head;
        head = head->next;
    }
    return pHead->next;
}
