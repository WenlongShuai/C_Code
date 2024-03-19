//  05_找单身狗
//  描述：一个数组中有两个数字只出现了一次，其他数字都出现了两次，我们现在需要把单独出现一次的两个数字找出来
// 输入：1 2 3 4 5 2 3 4
// 输出：1 5


#include <stdio.h>

void findAloneNum(int *arr, int sz)
{
    //方法一，先排序然后依次判断是否一个数字出现了两次
    //冒泡排序
//    int i = 0;
//    int j = 0;
//    for(i=0;i<sz-1;i++)
//    {
//        for(j=0;j<sz-1-i;j++)
//        {
//            int tmp = 0;
//            if(arr[j] > arr[j+1])
//            {
//                tmp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = tmp;
//            }
//        }
//    }
//
//    //进行判断每个元素在数组中出现的次数
//    int fixedPos = 0;
//    int movePos = 1;
//    while(1)
//    {
//        if(arr[fixedPos] == arr[movePos])
//        {
//            fixedPos = movePos+1;
//            movePos = fixedPos+1;
//        }
//        else
//        {
//            movePos++;
//        }
//
//        if(movePos == sz-1 || fixedPos == sz-1)
//        {
//            printf("%d ",arr[fixedPos]);
//            fixedPos++;
//            if(fixedPos == sz)
//            {
//                break;
//            }
//            movePos = fixedPos+1;
//        }
//    }
    
    //方法二，使用分组的方法实现
    //1 2 3 4 5 1 2 3 4 6
    //1、先将数组里面所有的元素异或起来，得到一个数字    1^2 ^3 ^ 4 ^ 5 ^ 1 ^ 2 ^ 3 ^ 4 ^ 6 == 3 -->011
    //2、将得到的数字转换成二进制，通过二进制中最右边的1进行分组   再次遍历数组，将每个元素二进制最低位为0的放在A数组，最低位为1的放在B数组
    //A[] = 6 2 2 4 4    B[] = 5 1 1 3 3
    //3、分为组之后再将每个组里面的元素异或，得到一个数字，这个数字就是这个单独数组的单身狗，另外一个数组同理。这样得到了整个数组的两个单身狗
    //A[] = 6^2^2^4^4 === 6   B[] = 5^1^1^3^3 === 5
    
    //1
    int i = 0;
    int ret = 0;
    int num1 = 0;
    int num2 = 0;
    for(i=0;i<sz;i++)
    {
        ret ^= arr[i];
    }
    
    //2
    int pos = 0;
    for(pos = 0;pos<32;pos++)
    {
        if(((ret>>pos)&1) == 1)
        {
            break;
        }
    }
    
    //3
    for(i=0;i<sz;i++)
    {
        if(((arr[i]>>pos)&1) == 1)  //A组
        {
            num1 ^= arr[i];
        }
        else            //B组
        {
            num2 ^= arr[i];
        }
    }
    
    printf("%d %d\n",num1,num2);
    
}

int main(int argc, const char * argv[])
{
    int arr[10] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    
    for(i=0;i<sz;i++)
    {
        scanf("%d",arr+i);
    }
    
    findAloneNum(arr, sz);
    
    
    return 0;
}
//10 9 8 7 9 8 7 6 6 1
//1 4 3 2 2 3 4 1 5 6
