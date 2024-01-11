//  06_求10个数的最大值

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num[10] = {20,15,3,5,25,12,15,13,12,11};
    int i = 0;
    int max = num[0];
    for(i=1;i<10;i++)
    {
        if(max < num[i])
        {
            max = num[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
