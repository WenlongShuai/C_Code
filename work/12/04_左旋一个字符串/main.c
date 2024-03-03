//  04_左旋一个字符串中的K个字符
//  ABCD 左旋一个字符得到 BCDA
//  ABCD 左旋两个字符得到 CDAB


#include <stdio.h>
#include <string.h>
#include <assert.h>

void levorotationStr(char *str,int k)
{
    assert(str);
    int len = strlen(str);
    k %= len;
    char tmp = 0;
    int i = 0;
    while(k--)
    {
        tmp = str[0];
        while(str[i+1] != '\0')
        {
            str[i] = str[i+1];
            i++;
        }
        str[i] = tmp;
        i = 0;
    }
}

int main(int argc, const char * argv[])
{
    char arr[20] = {0};
    int k = 0;

    scanf("%s %d",arr,&k);

    levorotationStr(arr,k);
    
    printf("%s\n",arr);
    
    return 0;
}
