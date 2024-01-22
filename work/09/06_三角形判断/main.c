//  main.c
//  06_三角形判断
//  判断3条边能否组成三角形，如果能，则判断出是什么三角形（等边三角形、等腰三角形、普通三角形）

#include <stdio.h>

void judgeTriangle(int a,int b,int c)
{
    if(a<b+c && b<a+c && c<a+b)
    {
        if((a==b && b!=c) || (a==c&&c!=b) || (b==c&&c!=a))
        {
            printf("isosceles triangle\n");  //等腰三角形
        }
        else if(a==b && b==c)
        {
            printf("equilateral triangle\n");  //等边三角形
        }
        else
        {
            printf("common triangle\n");  //普通三角形
        }
    }
    else
    {
        printf("Not a triangle\n");
    }
}

int main(int argc, const char * argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d",&a,&b,&c);
    judgeTriangle(a, b, c);
    return 0;
}
