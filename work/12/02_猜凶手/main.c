//  02_猜凶手
//  凶手为4个嫌疑犯其中的一个
//  供词如下
//    A说：不是我          killer != 'a'
//    B说：是C             killer == 'c'
//    C说：是D            killer == 'd'
//    D说：C在胡说         killer != 'd'
//    三个人说的真话，一个人说的假话

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int killer = 0;
    
    for(killer='a';killer<='d';killer++)
    {
        if(((killer!='a') + (killer=='c') + (killer=='d') + (killer!='d')) == 3)
        {
            printf("%c\n",killer);
        }
    }
    
    
    
    return 0;
}
