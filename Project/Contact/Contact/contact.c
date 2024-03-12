//  主要实现通讯录的功能

#include "contact.h"

void contactMenu()
{
    printf("------------------------------------\n");
    printf("---------------通讯录----------------\n");
    printf("---------0、exit    1、add-----------\n");
    printf("---------2、del     3、amend---------\n");
    printf("---------4、seek    5、show----------\n");
    printf("---------6、sort           ----------\n");
    printf("------------------------------------\n");
}

struct Contact* contactInit()
{
    //方式一：通过malloc向堆区申请一个100个结构体大小的内存
    struct Contact *contact = (struct Contact *)malloc(sizeof(struct Contact) * CONTACTNUM);
    int i = 0;
    struct Contact *tmp = contact;
    for(i=0;i<CONTACTNUM;i++,tmp++)
    {
        memset(tmp->name, 0, sizeof(tmp->name));
        tmp->age = 0;
        tmp->sex = male;
        memset(tmp->phone, 0, sizeof(tmp->phone));
        memset(tmp->address, 0, sizeof(tmp->address));
    }
    
    //方式二，直接定义一个结构体数组,全部初始化0
//    struct Contact contact[100] = {0};
    
    return contact;
}


void contactAdd(struct Contact *contact,char *name,int age,int sex,char *phone,char *address,int offset)
{
    contact += offset;
    assert(contact && name);
    strcpy(contact->name, name);
    contact->age = age;
    contact->sex = sex;
    strcpy(contact->phone, phone);
    strcpy(contact->address, address);
}

void contactDel(struct Contact *contact, char *delName)
{
    int i = 0;
    struct Contact *del = contactSeek(contact,delName);
    if(del == NULL)
    {
        printf("contact does not exist\n");
    }
    else
    {
        contact = del;
        memset(del->name, 0, sizeof(del->name));
        del->age = 0;
        del->sex = male;
        memset(del->phone, 0, sizeof(del->phone));
        memset(del->address, 0, sizeof(del->address));
        
        while(strcmp((contact+i+1)->name, ""))
        {
            strcpy((contact+i)->name, (contact+i+1)->name);
            (contact+i)->age = (contact+i+1)->age;
            (contact+i)->sex = (contact+i+1)->sex;
            strcpy((contact+i)->phone, (contact+i+1)->phone);
            strcpy((contact+i)->address, (contact+i+1)->address);
            i++;
        }
        memset((contact+i)->name, 0, sizeof((contact+i)->name));
        (contact+i)->age = 0;
        (contact+i)->sex = male;
        memset((contact+i)->phone, 0, sizeof((contact+i)->phone));
        memset((contact+i)->address, 0, sizeof((contact+i)->address));
        
        printf("delete success!\n");
    }
}

void contactAmend(struct Contact *contact, char *amendName)
{
    struct Contact *amend = contactSeek(contact,amendName);
    int option = 0;
    char name[20] = {0};
    int age = 0;
    enum Sex sex = male;
    char phone[11] = {0};
    char address[20] = {0};
    if(amend == NULL)
    {
        printf("contact does not exist!\n");
    }
    else
    {
        printf("------  输入选择以下选项--------\n");
        printf("------1、all    2、name-------\n");
        printf("------3、age    4、sex--------\n");
        printf("------5、phone  6、address----\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("请输入联系人所有信息：\n");
                scanf("%s%d%d%s%s",name,&age,&sex,phone,address);
                strcpy(amend->name, name);
                amend->age = age;
                amend->sex = sex;
                strcpy(amend->phone, phone);
                strcpy(amend->address, address);
                break;
            case 2:
                printf("请输入需要更改联系人的名字：\n");
                scanf("%s",name);
                strcpy(amend->name, name);
                break;
            case 3:
                printf("请输入需要更改联系人的年龄：\n");
                scanf("%d",&age);
                amend->age = age;
                break;
            case 4:
                printf("请输入需要更改联系人的性别：\n");
                scanf("%d",&sex);
                amend->sex = sex;
                break;
            case 5:
                printf("请输入需要更改联系人的电话：\n");
                scanf("%s",phone);
                strcpy(amend->phone, phone);
                break;
            case 6:
                printf("请输入需要更改联系人的地址：\n");
                scanf("%s",address);
                strcpy(amend->address, address);
                break;
            default:
                printf("输入有误!\n");
                break;
        }
        printf("amend success!\n");
    }
}

struct Contact *contactSeek(struct Contact *contact, char *seekName)
{
    //查找对应的联系人，如果找到了就返回联系人结构体地址，否则返回NULL
    while(strcmp(contact->name, ""))
    {
        if(!strcmp(contact->name, seekName))
        {
            return contact;
        }
        contact++;
    }
    
    return NULL;
}


void contactShow(struct Contact *contact)
{
    //显示通讯录的联系人
    assert(contact);
    while(strcmp(contact->name, ""))
    {
        printf("姓名:%s,年龄:%d,性别:%d,电话:%s,地址:%s\n",
               contact->name,contact->age,contact->sex,contact->phone,contact->address);
        contact++;
    }
}


//使用冒泡排序方法对结构体进行排序
//void qsort (void* base, size_t num, size_t size,  int (*compar)(const void*,const void*));

static void swap(char *s1, char *s2, int width)
{
    while(width--)
    {
        char tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
        s1++;
        s2++;
    }
}

static int comparStruct(const void *s1, const void *s2)
{
    //按照结构体中的姓名进行排序
    return strcmp(((struct Contact *)s1)->name, ((struct Contact *)s2)->name);
}

static void bubbleSort(void* base, int num, int size,  int (*compar)(const void*,const void*))
{
    int i = 0;
    int j = 0;
    
    for(i=0;i<CONTACTNUM-1;i++)
    {
        for(j=0;j<CONTACTNUM-1-i;j++)
        {
            if(strcmp(((struct Contact *)base+j+1)->name, ""))
            {
                if(compar((char *)base+size*j, (char *)base+size*(j+1)) > 0 )
                {
                    swap((char *)base+size*j, (char *)base+size*(j+1), size);
                }
            }
        }
    }
}

void contactSort(struct Contact *contact)
{
    bubbleSort(contact, CONTACTNUM, sizeof(struct Contact), comparStruct);
}

