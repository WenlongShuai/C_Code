//  03_杨辉三角形
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1



#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int input = 0;
    scanf("%d",&input);
    int arr[input][input];
    memset(arr, 0, sizeof(arr));
    int i = 0;
    int j = 0;
    
    for(i=0;i<input;i++)
    {
//        for(j=0;j<input;j++)
//        {
//            if(j==0)
//                arr[i][j] = 1;
//            else
//            {
//                if(i > 0)
//                    arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
//            }
//        }
        
        for(j=0;j<i+1;j++)   //这里的i+1表示，在i行的时候，这行对i个数据进行操作
        {
            if(j==0)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }

    for(i=0;i<input;i++)
    {
        for(j=0;j<input;j++)
        {
            if(arr[i][j] == 0)
                printf(" ");
            else
                printf("%d ",arr[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}
