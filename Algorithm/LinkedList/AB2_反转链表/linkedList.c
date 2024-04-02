//  linkedList.c

#include "linkedList.h"

struct Node* insertLikedList(struct Node *pHead, int num)
{
    //写法一
//    if(NULL == pHead)
//    {
//        pHead = (struct Node *)malloc(sizeof(struct Node));
//        if(pHead == NULL)
//        {
//            perror("insertLikedList malloc 1 error\n");
//            return NULL;
//        }
//        pHead->data = num;
//        pHead->next = NULL;
//        return pHead;
//    }
//    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
//    if(newNode == NULL)
//    {
//        perror("insertLikedList malloc 2 error\n");
//        return NULL;
//    }
//    newNode->next = pHead->next;
//    pHead->next = newNode;
//    newNode->data = num;
//    return newNode;
    
    //写法二
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

//定义三个结构体指针变量nextNode、nowNode、lastNode
//nextNode指向当前节点的下一个节点
//nowNode指向当前节点（头节点）
//lastNode指向当前节点的上一个节点的地址
struct Node* reversedLinkedList(struct Node* pHead)
{
    struct Node* nowNode = NULL;
    struct Node* lastNode = NULL;
    //tmp指向当前节点（nowNode）的下一个节点，假如头节点的上一个节点为NULL，那么tmp就指向现有链表的头节点
    struct Node* nextNode = pHead;
    //如果nowNode走到了最后一个节点，那么nowNode后一个节点就为NULL，那么tmp为NULL的时候，就说明链表已经遍历完了
    while(nextNode != NULL)
    {
        nowNode = nextNode;
        nextNode = nowNode->next;
        nowNode->next = lastNode;
        lastNode = nowNode;
    }
    return lastNode;
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


