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
    struct Count *count = (struct Count*)calloc(1,sizeof(struct Count));
    count->memoryCount = CONTACTMIN;
    contact = contactInit();
    loadContact(contact, count);
    int offset = 0;   ////静态内存申请时调用
    
    int option = 0;
    do
    {
        contactMenu();
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 0:
                saveContact(contact, count);
                destroyContact(contact);
                break;
            case add:     //add
//                contactAdd(contact, offset, option);  //静态内存申请时调用
//                offset++;   //静态内存申请时调用
                contactAdd(contact,count,option);   //动态内存申请的时候调用
                break;
            case del:     //del

                contactDel(contact, option);
                count->contactCount--;   //动态内存申请的时候调用
//                offset--;  //静态内存申请时调用
                break;
            case amend:     //amend
                contactAmend(contact, option);
                break;
            case seek:     //seek
            {
                struct Contact *seekContact = contactSeek(contact,NULL,option);
                if(seekContact == NULL)
                    printf("contact does not exist\n");
                else
                    printf("姓名:%s,年龄:%d,性别:%d,电话:%s,地址:%s\n",
                           seekContact->name,seekContact->age,seekContact->sex,seekContact->phone,seekContact->address);
            }
                break;
            case show:     //show
                contactShow(contact);
                break;
            case sort:     //sort
                contactSort(contact);
                break;
            default:
                printf("输入选项有误，请重新输入！\n");
                break;
        }
        
    }while(option);
    return 0;
}
