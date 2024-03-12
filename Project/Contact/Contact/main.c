//  Contact
//  实现一个通讯录
//    要求 ：
//    1、可以存放100个人的信息(姓名、年龄、性别、电话、地址)
//    2、增加联系人
//    3、删除联系人
//    4、修改联系人
//    5、查找联系人
//    6、联系人按名字顺序排序
//    7、显示所有联系人

#include <stdio.h>
#include "contact.h"

int main(int argc, const char * argv[])
{
    struct Contact *contact = NULL;
    contact = contactInit();
    int offset = 0;
    char name[20] = {0};
    int age = 0;
    enum Sex sex;
    char phone[11] = {0};
    char address[20] = {0};
    int option = 0;
    do
    {
        contactMenu();
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 0:
                break;
            case 1:     //add
                printf("请输入联系人信息：\n");
                printf("输入格式：姓名,年龄,性别,电话,地址\n");
                scanf("%s%d%d%s%s",name,&age,&sex,phone,address);
                contactAdd(contact, name, age, sex, phone, address, offset);
                offset++;
                break;
            case 2:     //del
                printf("请输入要删除的联系人名字\n");
                scanf("%s",name);
                contactDel(contact, name);
                offset--;
                break;
            case 3:     //amend
                printf("请输入要修改的联系人名字\n");
                scanf("%s",name);
                contactAmend(contact, name);
                break;
            case 4:     //seek
                printf("请输入要查找的联系人名字\n");
                scanf("%s",name);
                struct Contact *seekContact = contactSeek(contact, name);
                if(seekContact == NULL)
                    printf("contact does not exist\n");
                else
                    printf("姓名:%s,年龄:%d,性别:%d,电话:%s,地址:%s\n",
                           seekContact->name,seekContact->age,seekContact->sex,seekContact->phone,seekContact->address);
                break;
            case 5:     //show
                contactShow(contact);
                break;
            case 6:     //sort
                contactSort(contact);
                break;
            default:
                printf("输入选项有误，请重新输入！\n");
                break;
        }
        
    }while(option);
    return 0;
}
