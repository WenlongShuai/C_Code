//  01_将数字从大到小排序


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int j = 0;
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10-i-1;j++)
        {
            if(num[j] < num[j+1])
            {
                int temp = 0;
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    
    for(i = 0;i<10;i++)
    {
        printf("%d ",num[i]);
    }
    
    return 0;
}
