//  AB1_链表

//描述：请你实现一个链表。
//操作：insert x y：将y加入链表，插入在第一个值为x的结点之前。若链表中不存在值为x的结点，则插入在链表末尾。保证x,y为int型整数。
//delete x：删除链表中第一个值为x的结点。若不存在值为x的结点，则不删除。
//输入描述：
//第一行输入一个整数n，表示操作次数。
//接下来的n行，每行一个字符串，表示一个操作。保证操作是题目描述中的一种。
//输出描述：
//输出一行，将链表中所有结点的值按顺序输出。若链表为空，输出"NULL"(不含引号)。
//输入：
//5
//insert 0 1
//insert 0 3
//insert 1 2
//insert 3 4
//delete 4
//输出：
//2 1 3

#include <stdio.h>
#include "linkedList.h"

int main(int argc, const char * argv[])
{
    char input[10] = {0};
    int count = 0;
    int num = 0;
    int insertNum = 0;
    int deleteNum = 0;
    struct Node* headNode = linkedListInit();
    struct Node* start = headNode;
    scanf("%d",&count);
    
    while(count--)
    {
        scanf("%s",input);
        
        if(!strcmp(input, "insert"))
        {
            scanf("%d %d",&num, &insertNum);
            linkedListPush(headNode, num, insertNum);
        }
        else if(!strcmp(input, "delete"))
        {
            scanf("%d",&deleteNum);
            linkedListPop(headNode, deleteNum);
        }
        else
        {
            printf("input error\n");
            count++;
        }
    }
    linkedListPrint(start);
    
    return 0;
}
