//  BC13_ASCII码
//  将对应的ASCII码转换成对应的字符
//  例如：73，32，99，97，110，32，100，111，32，105，116，33

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int ascii[12] = {73,32,99,97,110,32,100,111,32,105,116,33};
    int i = 0;
    while(i < sizeof(ascii)/sizeof(ascii[0]))
    {
        //方式一
//        char c = (char)ascii[i];
//        printf("%c",c);
        
        //方式二
        printf("%c",ascii[i]);
        i++;
    }
    printf("\n");
    return 0;
}
