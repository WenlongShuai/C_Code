//  通讯录功能函数的声明
#ifndef contact_h
#define contact_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum Sex
{
    female,
    male,
    secrecy
};

struct Contact
{
    char name[20];
    int age;
    enum Sex sex;
    char phone[11];
    char address[20];
};

#define CONTACTNUM 100


void contactMenu();
struct Contact* contactInit();
void contactShow(struct Contact *contact);
void contactAdd(struct Contact *contact,char *name,int age,int sex,char *phone,char *address,int offset);
void contactDel(struct Contact *contact, char *delName);
void contactAmend(struct Contact *contact, char *amendName);
struct Contact *contactSeek(struct Contact *contact, char *findName);
void contactSort(struct Contact *contact);


#endif /* contact_h */
