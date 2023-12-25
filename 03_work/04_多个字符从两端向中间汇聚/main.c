//  04_多个字符从两端向中间汇聚
//  ####################
//  w##################!
//          .
//          .
//          .
//  welcome ## CHINA!!!!
//  welcome to CHINA!!!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    char arr1[] = "Welcome to CHINA!!!!!!!";
    char arr2[] = "#######################";
    int SZ = strlen(arr1)-1;
    int i = 0;
    for(i = 0;i <= SZ/2;i++)
    {
        arr2[i] = arr1[i];
        arr2[SZ-i] = arr1[SZ-i];
        sleep(1);
        printf("%s\n",arr2);
        system("clear"); //这是Mac OS系统的指令
        //system("Cls");   //这是Windows系统的指令
    }
    
    return 0;
}
