//  game.h
//  MineSweeper


#ifndef game_h
#define game_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define MINENUM 1

void menu();
void setMine(char mine[ROW][COL],int row,int col);
void gameInit(char show[ROW][COL],char mine[ROW][COL],int row,int col);
void mineClearance(char show[ROW][COL],char mine[ROW][COL],int row,int col);
void mineMenu(char mine[ROW][COL],int row,int col);
void showMenu(char show[ROW][COL],int row,int col);
void signMine(char show[ROW][COL],char mine[ROW][COL],int x,int y);


#endif /* game_h */
