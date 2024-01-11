//  05_模拟用户登陆场景
//  允许用户连续输入三次密码，如果正确则提示登录成功，否则退出程序

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char password[20] = {0};
    printf("请输入密码：");
    int i = 0;
    while(i < 3)
    {
        scanf("%s",password);
        if(strcmp(password,"123456") == 0)  //密码正确
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
            i++;
        }
    }
    return 0;
}
