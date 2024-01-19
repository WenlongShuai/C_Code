//  main.c
//  02_序列删除指定的数字
//  有一个整数序列（中间可能有重复的数字），现删除一个指定的整数，输出删除指定数字之后的序列，序列的数字顺序与原序列中数字位置不变
//  序列长度和序列中的数字满足 1 <= n <= 50
//  输入：6
//       1 2 3 3 5 7
//       3
//  输出：1 2 5 7


//  方法一    这方法时间复杂度比较高，如果遇到相等的元素之后，就要把数组后面的元素依次往前移动，如果后面有几万个数，就很费时间
//  将整数序列和序列大小、删除的整数通过传参给一个函数处理
//  1、循环判断删除的整数数字与整数序列的整数元素是否相等
//  2、如果相等则把整数序列后面的元素依次往前移动，以此达到删除想要删除的数字
//  3、移动之后继续判断当前元素是否与删除的数字相等，如果相等则执行第二步，否则执行第四步
//  3、如果不想等，则继续往后判断
//  4、直到循环完整数序列

//#include <stdio.h>
//void removeRepetitionNum(int num[],int *size,int removeNum)
//{
//    int i = 0;
//    int j = 0;
//    int len = *size;
//    while(i<len)
//    {
//        if(num[i] == removeNum)
//        {
//            for(j=i;j<len;j++)
//            {
//                num[j] = num[j+1];
//            }
//            (*size)--;
//        }
//        if(num[i] != removeNum)
//        {
//            i++;
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    int n = 0;
//    int i = 0;
//    scanf("%2d",&n);
//    int numArray[n];
//    int removeNum = 0;
//    for (i=0; i<n; i++)
//    {
//        scanf("%2d ",&numArray[i]);
//    }
//
//    scanf("%2d",&removeNum);
//
//    int size = sizeof(numArray)/sizeof(numArray[0]);
//    removeRepetitionNum(numArray,&size,removeNum);
//
//    for(i=0;i<size;i++)
//    {
//        printf("%d ",numArray[i]);
//    }
//
//    return 0;
//}



//  方法二  这个方法的时间复杂度比较低，最多只会遍历一次数组
//  1、定义两个变量i,j，i用于遍历整个整数序列，j用于指向不相等删除数字的元素
//  2、每判断一次i++，如果i指向的元素与删除数字相等，j就不变，否则j++
//  3、最后i遍历整个整数序列之后，就打印j个大小的数组，此时就为删除数字之后的数组
#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int numCount = 0;
    int numRemove = 0;
    scanf("%d",&numCount);
    int numArray[numCount];
    for(i=0;i<numCount;i++)
    {
        scanf("%d ",&numArray[i]);   //这里输入的时候，注意输入最后一个数字的时候要输入一个空格
    }
    scanf("%d",&numRemove);
    
    for(i=0;i<numCount;i++)
    {
        if(numArray[i] != numRemove)
        {
            numArray[j] = numArray[i];
            j++;
        }
    }
    
    for(i=0;i<j;i++)
    {
        printf("%d ",numArray[i]);
    }
    return 0;
}
