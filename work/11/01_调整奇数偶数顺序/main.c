//  main.c
//  01_调整奇数偶数顺序
//  有一个整形数组，把数组里面的奇数放在数组前段部分，把偶数放在数组后半部分


#include <stdio.h>

void swapParity(int *arr,int sz)
{
    int i = 0;
    int j = 0;
    for(i=0;i<sz;i++)
    {
        if(arr[i]%2 == 1 )   //奇数
        {
            for(j=i;j>0;j--)
            {
                
                if(arr[j-1]%2 == 0)
                {
                    int tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;
                }
            }
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
