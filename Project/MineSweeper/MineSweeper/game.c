//  game.c
//  MineSweeper


//// for循环判断极限坐标周围的点
//if(x==0 && y==0)  //坐标为(0,0)
//{
//    for(i=0;i<2;i++)
//    {
//        for(j=0;j<2;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//
//}
//else if(x==8 && y==0)  //坐标为(8,0)
//{
//    for(i=-1;i<1;i++)
//    {
//        for(j=0;j<2;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//}
//else if(x==0 && y==8)   //坐标为(0,8)
//{
//    for(i=0;i<2;i++)
//    {
//        for(j=-1;j<0;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//}
//else if(x==8 && y==8)       //  坐标为(8,8)
//{
//    for(i=-1;i<0;i++)
//    {
//        for(j=-1;j<0;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//}
//else if(x==0 && (y>=0 && y<COL))  //坐标为第一行
//{
//    for(i=0;i<2;i++)
//    {
//        for(j=-1;j<2;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//
//}
//else if(x==8 && (y>=0 && y<COL))   //坐标为最后一行
//{
//    for(i=-1;i<0;i++)
//    {
//        for(j=-1;j<2;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//}
//else if(y==0 && (x>=0 && x<ROW))  //坐标为第一列
//{
//    for(i=-1;i<2;i++)
//    {
//        for(j=0;j<2;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//
//}
//else  //坐标为最后一列
//{
//    for(i=-1;i<2;i++)
//    {
//        for(j=-1;j<0;j++)
//        {
//            count = count + mine[x+i][y+j] - '0';
//        }
//    }
//    return count - (mine[x][y] - '0');
//}
////  输入的坐标在第一行到最后一行，一列到最后一列之间，坐标周围就有8个点
//else
//{
//    for(i=-1;i<2;i++)
//    {
//        for(j=-1;j<2;j++)
//        {
//            printf("(%d,%d) = %d\n",x,y,mine[x+i][y-j]);
//            count = count + (mine[x+i][y-j]-'0');
//            printf("count = %d\n",count);
//        }
//    }
//}


#include "game.h"

extern int mineNum;
char temp[ROW][COL];

void menu()
{
    printf("------------------------------\n");
    printf("-----------1、Start-----------\n");
    printf("-----------0、Exit------------\n");
    printf("----------sign:1,1p-----------\n");
    printf("------mineClearance:1,1-------\n");
    printf("------------------------------\n");
}

//  扫雷初始化，将扫雷界面置为*
void gameInit(char show[ROW][COL],char mine[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            show[i][j] = '*';
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            mine[i][j] = '0';
        }
    }
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            temp[i][j] = '0';
        }
    }
}

//  显示扫雷的游戏界面，这个界面展示给玩家
void showMenu(char show[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    
    for(i=0;i<row;i++)
    {
        printf("%d ",i+1);
        for(j=0;j<col;j++)
        {
            printf("%c ",show[i][j]);
        }
        printf("\n");
    }
}

//  显示布雷的位置
void mineMenu(char mine[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i=0;i<row;i++)
    {
        printf("%d ",i+1);
        for(j=0;j<col;j++)
        {
            printf("%c ",mine[i][j]);
        }
        printf("\n");
    }
}

//  设置雷
void setMine(char mine[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    int i = 0;
    
    for(i=0;i<MINENUM;i++)
    {
        x = rand()%9;    //a+rand()%(b-a+1)
        y = rand()%9;
        if(x>=0 && x<=8 && y>=0 && y<=8)
        {
            mine[x][y] = '1';
        }
    }
}

//  得到输入坐标周围雷的个数
int getMineNum(char mine[ROW][COL],int x,int y)
{
    //输入的坐标为第一行或者最后一行，这时候坐标周围就没有8个点，只有3个点或者5个点
    if((x == 0 || x==ROW-1) && (y>=0 && y<COL))
    {
        if(x==0 && y==0)  //坐标为(0,0)
        {
            return mine[x][y+1]+mine[x+1][y]+mine[x+1][y+1] - 3*'0';
        }
        else if(x==ROW-1 && y==0)  //坐标为(8,0)
        {
            return mine[x-1][y]+mine[x-1][y+1]+mine[x][y+1]-3*'0';
        }
        else if(x==0 && y==COL-1)   //坐标为(0,8)
        {
            return mine[x][y-1]+mine[x+1][y-1]+mine[x+1][y]-3*'0';
        }
        else if(x==ROW-1 && y==ROW-1)       //  坐标为(8,8)
        {
           return mine[x-1][y-1]+mine[x-1][y]+mine[x][y-1]-3*'0';
        }
        else if(x==0 && (y>=0 && y<COL))  //坐标为第一行
        {
            return mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1] - 5*'0';
        }
        else   //坐标为最后一行
        {
            return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1] - 5*'0';
        }
    }
    //输入的坐标为第一列或者最后一列，这时候坐标周围就没有8个点，只有3个点或者5个点
    else if((x>=0 && x<ROW) && (y == 0 || y==COL-1))
    {
        if(y==0 && (x>=0 && x<ROW))  //坐标为第一列
        {
            return mine[x-1][y]+mine[x-1][y+1]+mine[x][y+1]+mine[x+1][y+1]+mine[x+1][y] - 5*'0';
        }
        else  //坐标为最后一列
        {
            return mine[x-1][y-1]+mine[x-1][y]+mine[x][y-1]+mine[x+1][y-1]+mine[x+1][y] - 5*'0';
        }
    }
    //  输入的坐标在第一行到最后一行，一列到最后一列之间，坐标周围就有8个点
    else
    {
            return mine[x-1][y+1]+
            mine[x][y+1]+
            mine[x+1][y+1]+
            mine[x-1][y]+
            mine[x+1][y]+
            mine[x-1][y-1]+
            mine[x][y-1]+
            mine[x+1][y-1]-8*'0';
    }
}

//  清除雷
void mineClearance(char show[ROW][COL],char mine[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    int num = row*col;
    char pattern = 0;
    while(num>MINENUM)
    {
        printf("请输入扫雷坐标->:");
        scanf("%d,%d%c",&x,&y,&pattern);
        if(x>=1 && x<=9 && y>=1 && y<=9)
        {
            if(pattern == 'p')
            {
                signMine(show, mine,x,y);
            }
            else
            {
                if(mine[x-1][y-1] == '1')
                {
                    printf("砰！踩到雷了!，游戏失败\n");
                    show[x-1][y-1] = '+';
                    showMenu(show, row, col);
                    break;
                }
                else
                {
                
                    spreadMine(show,mine,x,y);
//                    mineCount = getMineNum(mine, x-1, y-1);
//                    show[x-1][y-1] = mineCount+'0';
                    
                }
            }
            num--;
            mineMenu(mine, row, col);
            showMenu(show, row, col);
        }
        else
        {
            printf("输入非法坐标，请重新输入!\n");
        }
        
        if(mineNum == 0)   //把全部雷都标记正确
        {
            printf("恭喜，获得胜利!\n");
            break;
        }
    }
    if(num == MINENUM)
    {
        printf("恭喜，获得胜利!\n");
    }
}

// 标记雷
void signMine(char show[ROW][COL],char mine[ROW][COL],int x,int y)
{
    if(x>=1 && x<=9 && y>=1 && y<=9)
    {
        show[x-1][y-1] = '#';
        if(mine[x-1][y-1] == '1')
        {
            mineNum--;
        }
    }
}


//  如果坐标附近没有雷，则就展开不是雷的坐标
void spreadMine(char show[ROW][COL],char mine[ROW][COL],int x,int y)
{
    int i = 0;
    int j = 0;
    
    if(temp[x-1][y-1] == '1')
    {
        return;
    }
    
    if(getMineNum(mine,x-1,y-1) > 0 )
    {
        show[x-1][y-1] = getMineNum(mine,x-1,y-1) + '0';
        return;
    }
    else
    {
        for(i=-1;i<2;i++)
        {
            for(j=-1;j<2;j++)
            {
                if(x-1+i == 0 || x-1+i == ROW-1 || y-1+j == 0 || y-1+j == COL-1)
                {
                    continue;
                }
                temp[x-1+i][y-1+j] = '1';
                spreadMine(show,mine,x+i,y+j);
                show[x-1+i][y-1+j] = getMineNum(mine,x-1+i,y-1+j) + '0';
            }
        }
    }
}
