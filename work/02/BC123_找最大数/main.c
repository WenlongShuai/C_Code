//  BC123_找最大数
//  从4个整数中找到最大的一个数


#include <stdio.h>

int main(int argc, const char * argv[])
{
    //方法一
//    int value[4] = {0};
//    int i = 0;
//    int count = 0;
//    scanf("%d %d %d %d",&value[0],&value[1],&value[2],&value[3]);
//    int max = value[0];
//    for(i = 0;i < 3;i++)
//    {
//        if(max > value[i+1])
//        {
//            count++;
//        }
//        else
//        {
//            max = value[i+1];
//        }
//    }
//    if(count)
//    {
//        printf("%d\n",max);
//    }
//    else
//    {
//        printf("%d\n",value[3]);
//    }
    
    //方法二
//    int arr[4] = {0};
//    int i = 0;
//    while(i < 4)
//    {
//        scanf("%d",&arr[i]);
//        i++;
//    }
//    i = 1;
//    int max = arr[0];
//    while(i < 4)
//    {
//        if(max < arr[i])
//        {
//            max = arr[i];
//        }
//        i++;
//    }
//    printf("%d\n",max);
    
    //方法三
    int i = 0;
    int num = 0;
    int max = 0;
    scanf("%d",&max);
    while(i < 3)
    {
        scanf("%d",&num);
        if(max < num)
        {
            max = num;
        }
        i++;
    }
    printf("%d\n",max);
    return 0;
}
