//  05_找数字
//  一个矩形数组，从左到右数字从小到大。从上到下数字从小到大
//  寻找一个数字是否在这矩形中
//  要求：时间复杂度小雨O(N)
//  O(N):N个数据，每个数据都要去遍历一次。就相当于在N个元素的矩形中找一个数字，最坏的打算就要找N次

#include <stdio.h>

struct Point2
{
    int x;
    int y;
};

struct Point2 findNum(int (*str)[3], int row, int col, int k)
{
    int i =0 ;
    int j= 0 ;
 
    int x = 0;
    int y = col - 1;
    struct Point2 p = {-1,-1};
    while((x <= row-1) && (y >= 0))
    {
        if(str[x][y] < k)
            x++;
        else if(str[x][y] > k)
            y--;
        else
        {
            p.x = x;
            p.y = y;
            return p;   //表示找到
        }
        
    }
    return p;
}

int main(int argc, const char * argv[])
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    
    int k = 0;
    scanf("%d",&k);
    
    struct Point2 ret = findNum(arr,3,3,k);
    if(ret.x == -1 && ret.y == -1)
        printf("找不到\n");
    else
        printf("%d %d\n",ret.x, ret.y);
    
    return 0;
}
