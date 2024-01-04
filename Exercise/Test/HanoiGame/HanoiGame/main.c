//  HanoiGame


#include <stdio.h>

void Move(char x,char y)
{
    printf("%c-->%c ",x,y);
}

void Hanoi(int n,char a,char b ,char c)
{
    //    if(n == 2)
    //    {
    //        Move(a, b);
    //        Move(a, c);
    //        Move(b, c);
    //    }
    //    if(n == 3)
    //    {
    //        Move(a, c);
    //        Move(a, b);
    //        Move(c, b);
    //        Move(a, c);
    //        Move(b, a);
    //        Move(b, c);
    //        Move(a, c);
    //    }
    if(n == 1)
    {
        Move(a, c);
    }
    else
    {
        Hanoi(n-1, a, c, b);
        Move(a, c);
        Hanoi(n-1, b, a, c);
        
    }
    
}

int main(int argc, const char * argv[])
{
    int n = 0;
    scanf("%d",&n);
    
    Hanoi(n,'A','B','C');
    
    
    return 0;
}
