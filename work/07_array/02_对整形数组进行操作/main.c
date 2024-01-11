//  02_对整形数组进行操作
//  创建一个整形数组，完成对数组的操作
//  实现函数init()，数组初始化全为0
//  实现print()，打印数组元素
//  实现reverse()，完成数组的逆置


#include <stdio.h>

void init(int *arr,int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        arr[i] = 0;
    }
}

void print(int *arr,int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void reverse(int *arr,int len)
{
    int left = 0;
    int right = len-1;
    while(left<right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}

int main(int argc, const char * argv[])
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    print(arr,len);
    reverse(arr,len);
    print(arr,len);
    init(arr,len);
    print(arr,len);
    return 0;
}
