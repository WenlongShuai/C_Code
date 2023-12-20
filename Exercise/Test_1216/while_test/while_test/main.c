//  while_test
// 把输入字符串的大写字母转换成小写字母，小写字母转换成大写字母，将数字去掉

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char str[100];
    int i = 0;
    gets(str);
    while(str[i] != '\0')
    {
        
        if(str[i] >= 65 && str[i] <= 91)
        {
            str[i] += 32;
        }
        else if(str[i] >= 97 && str[i] <= 123)
        {
            str[i] -= 32;
        }
        else if(str[i] >= 48 && str[i] <= 57)
        {
            i++;
            continue;
        }
        else
        {
            str[i] += 0;
        }
        printf("%c",str[i]);
        i++;
    }
    printf("\n");
    return 0;
}
