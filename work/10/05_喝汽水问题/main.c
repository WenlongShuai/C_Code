//
//  main.c
//  05_喝汽水问题
//  汽水1元一瓶，两个空瓶可以换一瓶，给你20元，可以喝多少汽水

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int money = 0;
    int water = 0;
    int emptyBottle = 0;
    scanf("%d",&money);
    water = money;
    emptyBottle = water;
    
    while(emptyBottle >= 2)
    {
        water += emptyBottle/2;   //将空瓶换成汽水
        emptyBottle = emptyBottle/2 + emptyBottle%2;  //将现在的空瓶，加上之前的空瓶
    }
    printf("%d\n",water);
    
    return 0;
}
