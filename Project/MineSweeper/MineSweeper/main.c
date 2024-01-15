//  MineSweeper


#include "game.h"

int mineNum = 0;

int main(int argc, const char * argv[])
{
    char show[ROW][COL] = {0};
    char mine[ROW][COL] = {0};
    int row = ROW;
    int col = COL;
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        gameInit(show, mine, ROW, COL);
        mineNum = MINENUM;   //雷的个数
        printf("请选择选项->:");
        scanf("%d",&input);
        switch(input)
        {
            case 0:
                printf("退出游戏\n");
                break;
            case 1:
                printf("开始扫雷\n");
                setMine(mine, row, col);
                mineMenu(mine, row, col);
                printf("------------------------\n");
                showMenu(show, row, col);
                mineClearance(show, mine, row, col);
                break;
            default:
                printf("选择有误，请重新选择\n");
                break;
        }
    }while(input);
    
    return 0;
}
