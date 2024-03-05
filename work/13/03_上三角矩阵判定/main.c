//  03_上三角矩阵判定
//  判断一个n阶方矩是否为上三角矩阵。上三角则是主对角线以下的元素都是0，主对角线则是从左上角到右下脚的一条线
//  输入：
//      第一行，输入一个整数n，表示一个n*n的矩阵。
//      第二行，输入一个n*n的矩阵
//输出：
//      如果输入的方阵是上三角矩阵则输出YES，否则输出NO


//  方法一
//#include <stdio.h>
//int main(int argc, const char * argv[])
//{
//    int n = 0;
//    scanf("%d",&n);
//    int arr[n][n];
//    int i = 0;
//    int j = 0;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            scanf("%d",&arr[i][j]);
//        }
//    }
//    int flag = 1;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            if(i == j)   //不去判断主对角线以上的元素了
//            {
//                break;
//            }
//            if(arr[i][j] != 0)   //判断只要一个不为0就不是上三角
//            {
//                flag = 0;
//                goto end;
//            }
//        }
//    }
//
//end:
//    if(flag)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//
//
//    return 0;
//}


//方法二
//主对角线以下的元素坐标都有一个规律
//行的坐标大于列的坐标。 i>j
//#include <stdio.h>
//int main(int argc, const char * argv[])
//{
//    int n = 0;
//    scanf("%d",&n);
//    int arr[n][n];
//    int i = 0;
//    int j = 0;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            scanf("%d",&arr[i][j]);
//        }
//    }
//    int flag = 1;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<i;j++)
//        {
//            if(arr[i][j] != 0)
//            {
//                flag = 0;
//                goto end;
//            }
//        }
//    }
//
//end:
//    if(flag)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}


//方法三
//统计上三角0的个数
//公式：(n-1)*n/2
#include <stdio.h>
int main(int argc, const char * argv[])
{
    int n = 0;
    scanf("%d",&n);
    int arr[n][n];
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int count = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i == j)   //不去判断主对角线以上的元素了
            {
                break;
            }
            if(arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    
    if(count == ((n-1)*n/2))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    
    return 0;
}

