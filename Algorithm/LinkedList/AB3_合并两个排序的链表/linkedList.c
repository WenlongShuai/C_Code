//  linkedList.c

#include "linkedList.h"



struct Node* insertLinkedList(struct Node *pHead, int num)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("insertLinkedList malloc 1 %s\n",strerror(errno));
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


struct Node* merge(struct Node *pHead1,struct Node *pHead2)
{
    if(NULL == pHead1 && NULL == pHead2)
    {
        printf("{},{}\n");
        return NULL;
    }
    else if(NULL == pHead1 && NULL != pHead2)
    {
        return pHead2;
    }
    else if(NULL != pHead1 && NULL == pHead2)
    {
        return pHead1;
    }
    else
    {
        struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
        struct Node *p = newHead;
        
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->data < pHead2->data)
            {
                newHead->next = pHead1;
                pHead1 = pHead1->next;
                
            }
            else
            {
                newHead->next = pHead2;
                pHead2 = pHead2->next;
            }
            newHead = newHead->next;
        }
        
        if(pHead1 == NULL)
        {
            newHead->next = pHead2;
        }
        else
        {
            newHead->next = pHead1;
        }
        
        return p->next;
    }
}

void printLinkedList(struct Node *pHead)
{
    if(pHead == NULL)
    {
        printf("{}");
        return;
    }
    while(pHead != NULL)
    {
        printf("%d ",pHead->data);
        pHead = pHead->next;
    }
}

