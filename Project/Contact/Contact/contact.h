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

struct Count
{
    int contactCount;
    int memoryCount;
};




void contactMenu();
struct Contact* contactInit();
void saveContact(struct Contact *contact, struct Count *count);
void loadContact(struct Contact *contact, struct Count *count);

void printMenu(int num,char *name, int *age, int *sex, char *phone, char *address);
void destroyContact(struct Contact *contact);
void contactShow(struct Contact *contact);

//void contactAdd(struct Contact *contact, int offset, int option); //静态内存申请
void contactAdd(struct Contact *contact,struct Count *count,int option);  //动态内存申请
void contactDel(struct Contact *contact, int option);
void contactAmend(struct Contact *contact, int option);
struct Contact *contactSeek(struct Contact *contact, char *findName, int option);
void contactSort(struct Contact *contact);


#endif /* contact_h */
