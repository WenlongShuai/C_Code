//  AB12_删除链表的

#include <stdio.h>
#include "linkedList.h"

//描述：给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
//1.此题对比原题有改动
//2.题目保证链表中节点的值互不相同
//3.该题只会输出返回的链表和结果做对比，所以若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
//
//输入：{2,5,1,9},5
//返回值：{2,1,9}
//说明：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 2 -> 1 -> 9
//
//输入：{2,5,1,9},1
//返回值：{2,5,9}
//说明：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 2 -> 5 -> 9


int main(int argc, const char * argv[])
{
    int num = 0;
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    int flag = 0;
    while(1)
    {
        if(getchar() == '}')
        {
            getchar();
            break;
        }
        scanf("%d",&num);
        
        newNode = insertLikedList(newNode, num);
        if(!flag)
        {
            head = newNode;
            flag = 1;
        }
    }
    
    printf("------\n");
    printLinkedList(head);
    
    scanf("%d",&num);
    struct Node *deleteAfter = deleteLinkedListNode(head,num);
    
    printf("------\n");
    printLinkedList(deleteAfter);
    
    
    return 0;
}
