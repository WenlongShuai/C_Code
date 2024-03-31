//  linkedList.c

#include "linkedList.h"

struct Node
{
    int data;
    struct Node *next;
};

//链表初始化
struct Node* linkedListInit()
{
    //头节点
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL == headNode)
    {
        perror("linkedListInit malloc error\n");
//        printf("%s\n",strerror(errno));
        return NULL;
    }
    headNode->data = 0;
    headNode->next = NULL;
    return headNode;
}

//判断链表是否为空
static int linkedListIsEmpty(struct Node* headNode)
{
    if(headNode->next == NULL)
    {
        return 1;
    }
    return 0;
}


//查找链表中指定的值，并插入新值
void linkedListPush(struct Node *headNode, int num, insertNum)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if(NULL == node)
    {
        printf("linkedListPush malloc error:%s\n",strerror(errno));
        return ;
    }
    while(NULL != headNode->next)
    {
        //如果在链表中能找到指定的值，那就把新值插到它前面
        if(headNode->next->data == num)
        {
            node->data = insertNum;
            node->next = headNode->next;
            headNode->next = node;
            return;
        }
        headNode = headNode->next;
    }
    //如果没有找到指定的值，那就插到链表最后
    node->next = headNode->next;
    headNode->next = node;
    node->data = insertNum;
}

//删除指定值的节点
void linkedListPop(struct Node *headNode, int num)
{
    struct Node *node = NULL;
    while(NULL != headNode->next)
    {
        if(headNode->next->data == num)
        {
            node = headNode->next;
            node->data = 0;
            headNode->next = headNode->next->next;
            free(node);
            node = NULL;
            break;
        }
        headNode = headNode->next;
    }
}

//打印链表所有值
void linkedListPrint(struct Node *headNode)
{
    struct Node* tmp = headNode;
    int ret = linkedListIsEmpty(headNode);
    if(ret)
        printf("NULL\n");
    while(tmp->next != NULL)
    {
        printf("%d ",tmp->next->data);
        tmp = tmp->next;
    }
}
