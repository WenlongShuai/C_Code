//  03_二分查找有序数组的数
//  {1,2,3,4,5,6,7,8,9},使用二分查找法查找到元素为5

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 0;
    int i = 0;
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0])-1;
    int mid = 0;
    scanf("%d",&n);
    
    //step1:先将有序数组分为两部分，找到数组中间那个元素
    for(i = 0;left<=right ;i++)
    {
        //mid = (left + right)/2;   //这里有个弊端，如果left和right的值很大，整除2之后可能会超过int类型的范围
        mid = (right - left)/2 + left;
        //step2:查找到中间那个元素之后，与我们需要查到的数据进行对比
        //如果大于我们要找的数字，那么就把数组的开始位置移动到该位置+1的位置
        //如果小于我们要找的数字，那么就把数组的结束位置移动到该位置-1的地方
        if(arr[mid] > n)
        {
            right = mid - 1;
        }
        else if(arr[mid] < n)
        {
            left = mid + 1;
        }
        else
        {
            break;
        }
    }
    if(left <= right)
    {
        printf("找到了，下标为%d\n",mid);
    }
    else
    {
        printf("没找到\n");
    }
    
    return 0;
}
