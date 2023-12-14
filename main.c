//
//  main.c
//  01_Day
//
//  Created by mac on 2023/12/14.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char arr1[5] = {'a','b'};  //不完整初始化
    printf("%s\n",arr1);
    printf("%d\n",strlen(arr1));
    
    
    int a = 10;
    int arr2[a];  //C99标准之后，支持变长数组，允许数组的大小可以是变量，但是不能初始化
    
    char arr3[10] = "helloww";
    printf("%s\n",arr3);
    printf("%d\n",strlen(arr3));
    
    char arr4[] = {'a','b','c','d'};
    printf("%s\n",arr4);
    printf("%d\n",strlen(arr4));
    
    return 0;
}
