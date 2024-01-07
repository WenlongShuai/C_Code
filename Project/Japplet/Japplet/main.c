//  Japplet（三子棋游戏）


#include "game.h"

int main(int argc, const char * argv[])
{
    int n = 0;
    char chessboard[ROW][COL] = {0};
    srand((unsigned int)time(NULL));  //根据系统的时间戳随机产生一个数 0-32767
    do
    {
        menu();
        chessBoardInit(chessboard);
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                printf("退出游戏\n");
                break;
            case 1:
                printf("开始游戏\n");
                showChessboardMenu(chessboard);
                while(1)
                {
                    player(chessboard);
                    if(isVictory(chessboard) == PLAYER_PIECES)  //判断胜利
                    {
                        printf("玩家胜利！\n");
                        break;
                    }
                    if(isVictory(chessboard) == 'Q')
                    {
                        printf("平局\n");
                        break;
                    }
                    computer(chessboard);
                    if(isVictory(chessboard) == COMPUTER_PIECES)
                    {
                        printf("电脑胜利！\n");
                        break;
                    }
                    if(isVictory(chessboard) == 'Q')
                    {
                        printf("平局\n");
                        break;
                    }
                }
                break;
            default:
                printf("选项输入错误，请重新输入\n");
                break;
        }
    }while(n);
    
    
    return 0;
}
