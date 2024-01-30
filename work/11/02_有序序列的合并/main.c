//  main.c
//  02_有序序列的合并
//  输入两个有序序列，合并成一个序列
//  输入：5 7
//       1 2 3 4 5
//       6 7 8 9 10 11 12
//  输出：
//       1 2 3 4 5 6 7 8 9 10 11 12

#include <stdio.h>


//  方法一
//  1、每次分别提取两个序列数组的元素，进行比较，将小的数字放在合并数组开始，大的数字放在后面
//  2、存放完成之后，将上一步放入合并数组的小数字与它前一个进行比较，如果比它小则交换位置，再依次往前比较，直到比较到合并数组起始位置
//  3、再依次执行前两步
//void mergingSequences(int *sequences1, int *sequences2, int n, int m, int sz)
//{
//    int merging[sz];
//    int first = 0;
//    int second = 0;
//    int i = 0;
//    int j = 0;
//
//    while(i<sz)
//    {
//        if((first<n) && (second<m) && (sequences2[second] >= sequences1[first]))
//        {
//            merging[i] = sequences1[first];
//            merging[i+1] = sequences2[second];
//        }
//        else if((first<n) && (second<m) && (sequences2[second] < sequences1[first]))
//        {
//            merging[i] = sequences2[second];
//            merging[i+1] = sequences1[first];
//        }
//        else
//        {
//            if(first>n-1 && second<m)
//                merging[i] = sequences2[second];
//            else if(first<n && second>m-1)
//                merging[i] = sequences1[first];
//            else
//                break;
//        }
//
//        j = i;
//        do
//        {
//            if((j > 0) && (merging[j] < merging[j-1]))
//            {
//                int tmp = merging[j];
//                merging[j] = merging[j-1];
//                merging[j-1] = tmp;
//            }
//            else
//                break;
//            j--;
//        }while(1);
//
//        if((first<n) && (second<m))
//            i+=2;
//        else
//            i++;
//
//        first++;
//        second++;
//    }
//
//    for(i=0;i<sz;i++)
//    {
//        printf("%d ",merging[i]);
//    }
//    printf("\n");
//}

//  方法二
//  1、先取出两个数组的第一个元素，进行比较，如果第一个数组的元素小，那就将小的数字放入合并数组中
//  2、将第一个数组往后移动一个元素，在与第二个数组当前元素进行比较，
//      如果还是小于第二个数组当前元素的话，那就存入合并数组中，第一个数组继续移动到后一个元素与第二数组当前元素进行比较。
//      否则第二个数组就往后移一个元素。再次比较第一个数组当前元素比较

void mergingSequences(int *sequences1, int *sequences2, int n, int m, int sz)
{
    int merging[sz];
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i<n && j<m)
    {
        if(sequences1[i] < sequences2[j])
        {
            merging[k] = sequences1[i];
            k++;
            i++;
        }
        else
        {
            merging[k] = sequences2[j];
            k++;
            j++;
        }
    }
    
    if(i<n)
    {
        for(;i<n;i++)
        {
            merging[k] = sequences1[i];
            k++;
        }
    }
    else
    {
        for(;j<m;j++)
        {
            merging[k] = sequences2[j];
            k++;
        }
    }
    
    for(i=0;i<sz;i++)
    {
        printf("%d ",merging[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    scanf("%d%d",&n,&m);
    int sequences1[n];
    int sequences2[m];
    
    int sz = n+m;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",sequences1+i);
    }
    
    for(j=0;j<m;j++)
    {
        scanf("%d",sequences2+j);
    }
    
    mergingSequences(sequences1, sequences2,n,m,sz);
    
    
    return 0;
}
