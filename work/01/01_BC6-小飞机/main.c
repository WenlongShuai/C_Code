//
//  main.c
//  01_Homework
//
//  Created by mac on 2023/12/13.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
//    printf("     **\n");
//    printf("     **\n");
//    printf("************\n");
//    printf("************\n");
//    printf("    *  *    \n");
//    printf("    *  *    \n");
    
    for(int i = 0;i < 6;i++)
    {
        if(i < 2)
        {
            printf("     **\n");
        }
        else if(i >= 2 && i < 4)
        {
            printf("************\n");
        }
        else
        {
            printf("    *  *    \n");
        }
    }
    return 0;
}
