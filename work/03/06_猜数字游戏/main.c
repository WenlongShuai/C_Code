//  06_猜数字游戏
//  根据系统随机出的数字由我们来猜
//  如果猜的数字大于系统的数字，则提示猜大了
//  如果猜的数字小于系统的数字，则提示猜小了

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void menu()
{
    printf("------------- 1:Start -----------------\n");
    printf("------------- 0:Exit  -----------------\n");
    printf("请选择选项：");
}

void game()
{
    int randNum = rand()%100+1; //随机产生一个数，范围为1-100。a+rand()%(b-a+1)
    int guess = 0;
    while(1)
    {
        
        printf("请输入你猜的数字：");
        scanf("%d",&guess);
        if(guess > randNum)
        {
            printf("猜大了\n");
        }
        else if(guess < randNum)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("恭喜猜对了\n");
            break;
        }
    }
    
}

int main(int argc, const char * argv[])
{
    int choose = 0;
    srand((unsigned int)time(NULL));   //种下一颗种子，这个种子跟着时间戳的变化而变化
    while(1)
    {
        menu();
        scanf("%d",&choose);
        switch (choose)
        {
            case 1:
                game();
                break;
            case 0:
                return 0;
            default:
                printf("输入错误\n");
                break;
        }
    }
    return 0;
}
