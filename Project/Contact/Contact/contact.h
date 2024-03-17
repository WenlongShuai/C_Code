//  通讯录功能函数的声明
#ifndef contact_h
#define contact_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>



#define CONTACTNUM 100  //静态申请空间
#define CONTACTMIN 3    //动态申请最小空间
#define ADDMEMORY 2     //每次动态增加内存的个数

enum Sex
{
    female,
    male,
    secrecy
};

enum Option
{
    add=1,  //添加
    del,    //删除
    amend,  //修改
    seek,   //查询
    show,   //显示
    sort    //排序
};

struct Contact
{
    char name[20];
    int age;
    enum Sex sex;
    char phone[11];
    char address[20];
};

//用来记录通讯录联系人的个数。以及内存的大小
struct Count
{
    int contactCount;
    int memoryCount;
};




void contactMenu();   //打印通讯录的功能选项
struct Contact* contactInit();   //初始化通讯录
void saveContact(struct Contact *contact, struct Count *count);   //将内存里的联系人保存到硬盘的文本数据中
void loadContact(struct Contact *contact, struct Count *count);  //将硬盘的文本数据加载到内存中来

void printMenu(int num,char *name, int *age, int *sex, char *phone, char *address);   //打印功能选项的提示信息
void destroyContact(struct Contact *contact);  //退出通讯录的时候释放在堆上开辟的内存空间
void contactShow(struct Contact *contact);   //显示通讯录的所有联系人信息

//void contactAdd(struct Contact *contact, int offset, int option); //静态内存申请
void contactAdd(struct Contact *contact,struct Count *count,int option);  //动态内存申请
void contactDel(struct Contact *contact, int option);   //删除联系人功能
void contactAmend(struct Contact *contact, int option);   //修改联系人功能
struct Contact *contactSeek(struct Contact *contact, char *findName, int option);   //查找联系人的功能
void contactSort(struct Contact *contact);  //把添加的联系人进行升序排序


#endif /* contact_h */
