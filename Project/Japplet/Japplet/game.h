//  game.h
//  Japplet
//  声明游戏的功能函数

#ifndef game_h
#define game_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROW 3
#define COL 3
#define PLAYER_PIECES '*'
#define COMPUTER_PIECES '#'

void menu();
void showChessboardMenu(char board[ROW][COL]);
void player(char board[ROW][COL]);
void computer(char board[ROW][COL]);
char isVictory(char board[ROW][COL]);
void chessBoardInit(char board[ROW][COL]);
void computerJudge(char board[ROW][COL],int x,int y);


#endif /* game_h */
