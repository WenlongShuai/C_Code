//  02_矩形转置
//  输入：2   3
//      1 2 3
//      4 5 6
//  输出：1 4
//       2 5
//       3 6

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int m = 0;
    int n = 0;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    int transposedArr[m][n];
    int i = 0;
    int j = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    
    for(j=0;j<m;j++)
    {
        for (i=0; i<n; i++)
        {
            transposedArr[j][i] = arr[i][j];
        }
    }
    

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",transposedArr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
