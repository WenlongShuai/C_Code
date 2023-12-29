/*实现一个栈
操作：
 push x：将x入栈，保证x是int型整数
 pop：输出栈顶，并让栈顶出栈
 top：输出栈顶，栈顶不出栈
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//每个元素的结点
struct StackNode
{
    int data;
    struct StackNode *next;
};

//头结点
struct HeadNode
{
    struct StackNode *head;
};

struct HeadNode* StackInit()
{
    struct StackNode* node = (struct StackNode *)malloc(sizeof(struct StackNode));
    struct HeadNode* T = (struct HeadNode *)malloc(sizeof(struct HeadNode));
    T->head = node;
    node->next = NULL;
    return T;
}

int Empty(struct HeadNode *T)
{
    if(T->head->next != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void PrintStack(struct HeadNode *T)
{
    struct StackNode* temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    temp = T->head->next;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void PushOperation(struct HeadNode *T,int d)
{
    //printf("push\n");
    struct StackNode *p = (struct StackNode *)malloc(sizeof(struct StackNode));
    p->next = T->head->next;
    T->head->next = p;
    p->data = d;
}

void PopOperation(struct HeadNode *T)
{
    //printf("POP\n");
    if(Empty(T))
    {
        printf("error\n");
        return ;
    }
    struct StackNode *p = T->head->next;
    T->head->next = p->next;
    printf("%d\n",p->data);
    p = NULL;
    free(p);
}

void TopOperation(struct HeadNode *T)
{
    //printf("top\n");
    if(Empty(T))
    {
        printf("error\n");
        return ;
    }
    printf("%d\n",T->head->next->data);
}

//void InputOperation(char* operation,struct HeadNode* T)
//{
//    int result;
//    int num = 0;
//    if(operation==NULL)
//    {
//        printf("input operation is NULL\n");
//    }
//    else
//    {
//        if(!strcmp(operation, "push"))
//        {
//            result = 0;
//        }
//        else if(!strcmp(operation, "pop"))
//        {
//            result = 1;
//        }
//        else if(!strcmp(operation, "top"))
//        {
//            result = 2;
//        }
//        else
//        {
//            printf("input operation is error\n");
//            return;
//        }
//
//        switch(result)
//        {
//            case 0:      //执行push
//                scanf("%d",&num);
//                PushOperation(T,num);
//                break;
//            case 1:     //执行pop
//                PopOperation(T);
//                break;;
//            case 2:     //  执行top
//                TopOperation(T);
//                break;
//        }
//    }
//}


int main(int argc, const char * argv[])
{
    int time = 0;
    int num = 0;
    //char *str;   //如果写成这种格式有些编译器会报错，显示数组越界。因为是一个指针变量，指向的内存地址不确定
    char str[20] = {0};  //写成这种格式是最恰当的
    struct HeadNode* T = StackInit();
    scanf("%d",&time);
    
    
    while(time)
    {
        scanf("%s",str);
        
        if(!strcmp(str, "push"))
        {
            scanf("%d",&num);
            PushOperation(T,num);
        }
        else if(!strcmp(str, "pop"))
        {
            PopOperation(T);
        }
        else if(!strcmp(str, "top"))
        {
            TopOperation(T);
        }
        else
        {
            printf("input error\n");
            break;
        }
        time--;
        
    }
    return 0;
}
