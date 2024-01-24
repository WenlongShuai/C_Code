//  main.c
//  01_字符串逆序打印
//  输入：hello
//  输出：olleh


#include <stdio.h>
#include <string.h>


//  方法一
//  使用中间变量交换字符串头尾的字符
//void printReversedOrder(char *arr,int sz)
//{
//    int left = 0;
//    int right = sz-1;
//
//    char tmp = 0;
//    while(left < right)
//    {
//        tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//    printf("%s\n",arr);
//}

// 方法二
//  使用递归的方法交换字符串
void printReversedOrder(char *arr)
{
    char tmp = 0;
    int sz = strlen(arr);
    if(sz < 1)
    {
        return;
    }
    tmp = *arr;
    *arr = arr[sz-1];
    arr[sz-1] = '\0';
    printReversedOrder(arr+1);
    arr[sz-1] = tmp;
}

int main(int argc, const char * argv[])
{
    char inputArr[10001] = {0};

    //  方法一
    //  fgets()这种方法会把输入流中的'\n'读出来
    //  比如在键盘上输入:“hello”
    //  实际fgets()会读取“hello\n\0”
//    //  如果用strlen()函数求字符串长度，则需要-1
//    fgets(inputArr, sizeof(inputArr)/sizeof(inputArr[0]), stdin);
//    int sz = strlen(inputArr)-1;

    //gets()方法则不会从输入流读取'\n'，所以在用strlen()函数求字符串长度时则不需要-1
//    gets(inputArr);
//    int sz = strlen(inputArr);
//    printReversedOrder(inputArr,sz);
    
    //  方法二
    fgets(inputArr, sizeof(inputArr)/sizeof(inputArr[0]), stdin);
    printReversedOrder(inputArr);
    printf("%s\n",inputArr);
    
    return 0;
}
