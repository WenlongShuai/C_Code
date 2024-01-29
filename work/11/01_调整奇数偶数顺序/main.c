//  main.c
//  01_调整奇数偶数顺序
//  有一个整形数组，把数组里面的奇数放在数组前段部分，把偶数放在数组后半部分


#include <stdio.h>

//  方法一
//  1、先判断数组第i个元素是否为奇数
//  2、如果i个元素为基数，则判断前一个元素i-1是否偶数，如果是偶数，则交换位置
//  3、交换位置之后，在用i-1的元素去与i-2的元素进行判断
//  4、依次重复上面步骤，直到遍历完数组
//void swapParity(int *arr,int sz)
//{
//    int i = 0;
//    int j = 0;
//    for(i=0;i<sz;i++)
//    {
//        if(arr[i]%2 == 1 )   //奇数
//        {
//            for(j=i;j>0;j--)
//            {
//
//                if(arr[j-1]%2 == 0)
//                {
//                    int tmp = arr[j];
//                    arr[j] = arr[j-1];
//                    arr[j-1] = tmp;
//                }
//            }
//        }
//    }
//}

//  方法二
//  1、先定义两个变量，分别指向数组的开头和结尾
//  2、开头的变量就去寻找偶数，遇到偶数就停止
//  3、结尾的变量就去寻找奇数，遇到奇数就停止
//  4、当两个变量都停止之后，就交换两个变量指向的元素
//  5、直到开头的变量大于结尾的变量
void swapParity(int *arr,int sz)
{
    int left = 0;
    int right = sz-1;
    
    while(left<right)
    {
        //去寻找偶数
        //这个判断条件会导致栈溢出，数组越界访问。因为当数组全为奇数的时候，就会一直循环下去，所以left就会一直往下加
//        while(arr[left]%2==1)
//        {
//            left++;
//        }
        
        //如果数组全为奇数，那么就一直找到right的地方就会停止，这样就不会存在越界的问题
        while((left<right) && (arr[left]%2==1))
        {
            left++;
        }
        
        //去寻找奇数
        //这个判断条件会导致栈溢出，数组越界访问。因为当数组全为偶数的时候，就会一直循环下去，所以right就会一直往下加
//        while(arr[right]%2==0)
//        {
//            right++;
//        }
        
        //如果数组全为偶数，那么就一直找到left的地方就会停止，这样就不会存在越界的问题
        while((left<right) && (arr[right]%2==0))
        {
            right--;
        }
        
        if(left<right)
        {
            int tmp = 0;
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            //交换完元素之后，跳过这两个元素
            left++;
            right++;
        }
    }
    
}

int main(int argc, const char * argv[])
{
    int arr[10] = {0};
    int i = 0;
    for(i=0;i<10;i++)
    {
        scanf("%d",arr+i);
    }
    int sz = sizeof(arr)/sizeof(arr[0]);
    swapParity(arr,sz);
    
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
