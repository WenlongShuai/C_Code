//struct结构体    创建的结构体数据类型不会申请内存

#include <stdio.h>

//定义一个学生类的结构体，类包括学号、姓名、年龄、性别
//1、直接定义一个结构体数据类型
struct Stu
{
    int No;
    char *Name;
    int Age;
    char *Sex;
};

//2、使用typedef关键字给结构体数据类型重命名
typedef struct Stu1
{
    int No;
    char *Name;
    int Age;
    char *Sex;
}S;

int main(int argc, const char * argv[]) {
    
    //定义一个结构体数据类型的变量
    struct Stu s = {111,"zhangsan",15,"男"};
    printf("%d %s %d %s\n",s.No,s.Name,s.Age,s.Sex);
    //定义一个结构体数据类型的指针变量,存储s变量的地址
    struct Stu* s1 = &s;
    printf("%d %s %d %s\n",s1->No,s1->Name,s1->Age,s1->Sex);  //使用 -> 操作符访问结构体的成员
    printf("%d %s %d %s\n",(*s1).No,(*s1).Name,(*s1).Age,(*s1).Sex);  //使用 . 操作符访问结构体的成员
    
    return 0;
}
