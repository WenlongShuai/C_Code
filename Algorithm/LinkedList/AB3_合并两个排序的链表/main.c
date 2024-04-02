//  main.c
//  AB3_合并两个排序的链表

//描述：输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
//数据范围：0≤n≤1000，−1000≤节点值≤1000
//要求：空间复杂度O(1)，时间复杂度O(n)
//如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}。
//或输入{-1,2,4},{1,3,4}时，合并后的链表为{-1,1,2,3,4,4}，所以对应的输出为{-1,1,2,3,4,4}。
//
//输入：{1,3,5},{2,4,6}
//返回值：{1,2,3,4,5,6}
//
//输入：{},{}
//返回值：{}
//
//输入：{-1,2,4},{1,3,4}
//返回值：{-1,1,2,3,4,4}


#include <stdio.h>
#include "linkedList.h"

int main(int argc, const char * argv[])
{
    int num = 0;
    int twoListFlag = 0;
    int headNodeFlag1 = 0;
    int headNodeFlag2 = 0;
    struct Node *pHead1 = NULL;
    struct Node *pHead2 = NULL;
    struct Node *newNode1 = NULL;
    struct Node *newNode2 = NULL;
    
    while(1)
    {
        if(twoListFlag == 0 && getchar() == '}')
        {
            twoListFlag = 1;
            getchar();
        }
        if(twoListFlag == 1 && getchar() == '}')
        {
            break;
        }
        
        scanf("%d",&num);
        if(!twoListFlag)
        {
            newNode1 = insertLinkedList(newNode1, num);
            if(!headNodeFlag1)
            {
                pHead1 = newNode1;
                headNodeFlag1 = 1;
            }
        }
        else
        {
            newNode2 = insertLinkedList(newNode2, num);
            if(!headNodeFlag2)
            {
                pHead2 = newNode2;
                headNodeFlag2 = 1;
            }
        }
    }
    
    printLinkedList(pHead1);
    printf("----\n");
    printLinkedList(pHead2);
    printf("----\n");
    struct Node* mergeList = merge(pHead1,pHead2);
    printLinkedList(mergeList);
    return 0;
}
