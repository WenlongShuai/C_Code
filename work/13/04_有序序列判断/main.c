//  04_有序序列判断
//  判断一个序列是否有序。从大到小或者从小到大或者相等都是为有序
//  输入：5
//      1 3 5 6 7
//  输出：sorted

//  输入：5
//      1 3 2 4 5
//  输出：unsorted

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    int i = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    
    int flag = 0;
    int flag2 = 0;
    
    for(i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])   //判断是否是从大到小排序
            flag = 1;
        else if(arr[i] < arr[i+1])   //判断是否是从大到小排序
            flag2 = 1;
        else   //如果相等什么都不做
            ;
    }
    
    if(flag+flag2 <= 1)
    {
        printf("sorted\n");
    }
    else
    {
        printf("unsorted\n");
    }
    
    return 0;
}
