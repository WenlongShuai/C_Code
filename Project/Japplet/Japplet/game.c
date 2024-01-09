//  game.c
//  Japplet
//  实现游戏的功能函数

#include "game.h"

void menu()
{
    printf("-----------------------------\n");
    printf("------------1.Start----------\n");
    printf("------------0.Exit-----------\n");
    printf("-----------------------------\n");
}

void chessBoardInit(char board[ROW][COL])
{
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            board[i][j] = ' ';
        }
    }
}

void showChessboardMenu(char board[ROW][COL])
{
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(j == (COL-1))
            {
                printf(" %c ",board[i][j]);
            }
            else
            {
                printf(" %c |",board[i][j]);
            }
        }
        printf("\n");
        if(i < ROW-1)
        {
            for(j=0;j<ROW;j++)
            {
                if(j == (COL-1))
                {
                    printf("---");
                }
                else
                {
                    printf("---|");
                }
            }
        }
        printf("\n");
    }
}

void player(char board[ROW][COL])
{
    int x = 0;
    int y = 0;
    int ch = 0;
    while(1)
    {
        printf("玩家请输入坐标->");
        scanf("%d %d",&x,&y);
        if((x >=1 && x <= 3) && (y >= 1 && y <= 3) )
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = PLAYER_PIECES;
                showChessboardMenu(board);
                break;
            }
            else
            {
                printf("此坐标已有棋子，请重新输入其他坐标\n");
            }
        }
        else
        {
            printf("输入坐标有误，请重新输入\n");
            while(ch != '\n')
            {
                ch = getchar();
            }
        }
    }
}

void computer(char board[ROW][COL])
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("电脑请下棋\n");
        x = rand()%3;
        y = rand()%3;
        if(board[x][y] == ' ')
        {
//            board[x][y] = COMPUTER_PIECES;
            computerJudge(board,x,y);
            showChessboardMenu(board);
            break;
        }
    }
}

//如果棋盘满了饭回1，否则返回0
int isFull(char board[ROW][COL])
{
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

char isVictory(char board[ROW][COL])
{
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++)
    {
        if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && board[i][1]!=' ')
        {
            return board[i][1];
        }
    }
    for(j=0;j<COL;j++)
    {
        if((board[0][j]==board[1][j]) && (board[1][j]==board[2][j]) && board[1][j]!=' ')
        {
            return board[1][j];
        }
    }

    if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && board[1][1]!=' ')
    {
        return board[1][1];
    }
    else if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && board[1][1]!=' ')
    {
        return board[1][1];
    }
    
    if(isFull(board))
    {
        return 'Q';
    }
    else
    {
        return 'C';
    }
}

void computerJudge(char board[ROW][COL],int x,int y)
{
    int i = 0;
    int j = 0;
    //防守
    //反斜线判断
    if(board[0][0]==PLAYER_PIECES && board[1][1]==PLAYER_PIECES)
    {
        if(board[2][2] == ' ')
        {
            board[2][2] = COMPUTER_PIECES;
            return;
        }
    }
    else if(board[1][1]==PLAYER_PIECES && board[2][2]==PLAYER_PIECES)
    {
        if(board[0][0]==' ')
        {
            board[0][0] = COMPUTER_PIECES;
            return;
        }
    }
    else if(board[0][0]==PLAYER_PIECES && board[2][2]==PLAYER_PIECES)
    {
        if(board[1][1]==' ')
        {
            board[1][1] = COMPUTER_PIECES;
            return;
        }
    }
    //斜线判断
    else if(board[0][2]==PLAYER_PIECES && board[1][1]==PLAYER_PIECES)
    {
        if(board[2][0]==' ')
        {
            board[2][0] = COMPUTER_PIECES;
            return;
        }
    }
    else if(board[0][2]==PLAYER_PIECES && board[2][0]==PLAYER_PIECES)
    {
        if(board[1][1]==' ')
        {
            board[1][1] = COMPUTER_PIECES;
            return;
        }
    }
    else if(board[1][1]==PLAYER_PIECES && board[2][0]==PLAYER_PIECES)
    {
        if(board[0][2]==' ')
        {
            board[0][2] = COMPUTER_PIECES;
            return;
        }
    }
    //行判断
    for(i=0;i<ROW;i++)
    {
        if(board[i][0]==PLAYER_PIECES && board[i][1]==PLAYER_PIECES)
        {
            if(board[i][2]==' ')
            {
                board[i][2] = COMPUTER_PIECES;
                return;
            }
        }
        else if(board[i][1]==PLAYER_PIECES && board[i][2]==PLAYER_PIECES)
        {
            if(board[i][0]==' ')
            {
                board[i][0] = COMPUTER_PIECES;
                return;
            }
        }
        else if(board[i][0]==PLAYER_PIECES && board[i][2]==PLAYER_PIECES)
        {
            if(board[i][1]==' ')
            {
                board[i][1] = COMPUTER_PIECES;
                return;
            }
        }
    }
    
    //列判断
    for(j=0;j<COL;j++)
    {
        if(board[0][j]==PLAYER_PIECES && board[1][j]==PLAYER_PIECES)
        {
            if(board[2][j]==' ')
            {
                board[2][j] = COMPUTER_PIECES;
                return;
            }
        }
        else if(board[1][j]==PLAYER_PIECES && board[2][j]==PLAYER_PIECES)
        {
            if(board[0][j]==' ')
            {
                board[0][j] = COMPUTER_PIECES;
                return;
            }
        }
        else if(board[0][j]==PLAYER_PIECES && board[2][j]==PLAYER_PIECES)
        {
            if(board[1][j]==' ')
            {
                board[1][j] = COMPUTER_PIECES;
                return;
            }
        }
    }
    
    
    //进攻
    if(board[1][1]==' ')
    {
        board[1][1] = COMPUTER_PIECES;
    }
    else
    {
        if(board[0][0]==' ')
        {
            board[0][0] = COMPUTER_PIECES;
        }
        else if(board[0][2]==' ')
        {
            board[0][2] = COMPUTER_PIECES;
        }
        else if(board[2][0]==' ')
        {
            board[2][0] = COMPUTER_PIECES;
        }
        else if(board[2][2]==' ')
        {
            board[2][2] = COMPUTER_PIECES;
        }
        else
        {
            board[x][y] = COMPUTER_PIECES;
        }
    }
}
