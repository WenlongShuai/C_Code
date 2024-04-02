//
//  main.c
//  AB2_反转链表

#include <stdio.h>
#include "linkedList.h"

int main(int argc, const char * argv[])
{
    int num = 0;
    int flag = 1;
    struct Node *pHead = NULL;
    struct Node *newNode = NULL;
    while(1)
    {
        if(getchar() == '}')
        {
            break;
        }
        if(scanf("%d",&num) != 0)
        {
            //将当前节点的地址传进去，在这个地址的基础上开辟一个新的节点，返回新节点的地址，然后又传进去，依次循环，直到把所有的数据插入到链表
            newNode = insertLikedList(newNode, num);
            if(flag)
            {
                pHead = newNode; //这里是为了保存链表的头节点，不然后面就这个链表
                flag = 0;
            }
        }
    }
    printLinkedList(pHead);
    
    printf("------\n");
    struct Node* revseredNode = reversedLinkedList(pHead);
    
    printLinkedList(revseredNode);
    return 0;
}
