//  使用冒泡排序实现库函数qsort
//qsort库函数的原型，该排序的算法是使用快速排序
//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
//void* base：需要排序的数据的起始位置
//size_t num：需要排序数据的元素个数
//size_t size：需要排序数据的每个数据的大小
//int (*compar)(const void*,const void*)：函数指针，用于排序数据的比较。需要用户自己实现比较函数，然后函数作为参数传入qsort函数

//1、使用库函数进行数据排序
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////先使用库函数进行数据排序
//int compar_int(const void* e1,const void* e2)
//{
////    return e1-e2;   //error。因为void*的指针不知道数据的具体类型，不能进行运算，如果要进行运算，就要强制转换为想要的类型
//    return *(int*)e1-*(int*)e2;
//}
//
////使用qsort对整型数组进行排序
//void test1()
//{
//    int arr[10] = {1,0,4,5,2,3,8,9,6,7};
//    int sz = sizeof(arr)/sizeof(arr[0]);
//    qsort(arr,sz,sizeof(int),compar_int);
//    int i = 0;
//    for(i=0;i<sz;i++)
//    {
//        printf("%d ",arr[i]);
//    }
//}
//
////使用qsort对结构体数组进行排序
//struct Stu
//{
//    char name[20];
//    int age;
//};
//
//int compar_struct(const void* e1,const void* e2)
//{
////    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;  //按照结构体的年龄排序
//    return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name); ////按照结构体的姓名排序
//}
//void test2()
//{
//    struct Stu s[] = {{"zhangsan",18},{"lisi",23},{"wangwu",20}};
//    int sz = sizeof(s)/sizeof(s[0]);
//    qsort(s,sz,sizeof(struct Stu),compar_struct);
//    int i = 0;
//    for(i=0;i<sz;i++)
//    {
//        printf("%s %d\n",s[i].name,s[i].age);
//    }
//}
//
//int main(int argc, const char * argv[])
//{
////    test1();
//    test2();
//    return 0;
//}



//2、自己使用冒泡算法来实现qsort函数
#include <stdio.h>
#include <string.h>

//交换两个元素
//根据数据的类型宽度来进行交换
//如果是两个char类型的数据，宽度为1，则交换一次
//如果是两个int类型的数据，宽度为4，每次交换一个字节的数据，则需要交换4次来达到整型数据的交换
void swap(char* e1,char *e2,int width)
{
    int i = 0;
    for(i=0;i<width;i++)
    {
        char tmp = *e1;
        *e1 = *e2;
        *e2 = tmp;
        e1++;
        e2++;
    }
}

//比较两个数
int compar_int(const void* e1,const void* e2)
{
    return *((int*)e2) - *((int*)e1);
}

//使用冒泡算法实现qsort函数
void bubble_sort(void* base,int sz,int width,int(*compar_int)(const void* e1,const void* e2))
{
    int i = 0;
    int j = 0;
    for(i=0;i<sz-1;i++)
    {
        for(j=0;j<sz-i-1;j++)
        {
            if(compar_int((char*)base+j*width,(char*)base+(j+1)*width) > 0)
            {
                swap((char*)base+j*width,(char*)base+(j+1)*width,width);
            }
        }
    }
}

void test3()
{
    int arr[10] = {1,0,4,5,2,3,8,9,6,7};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,sz,sizeof(int),compar_int);
    
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
}


struct Stu
{
    char name[20];
    int age;
};

int compar_struct(const void* e1,const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;  //按照结构体的年龄排序
//    return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name); ////按照结构体的姓名排序
}
void test4()
{
    struct Stu s[] = {{"zhangsan",18},{"lisi",23},{"wangwu",20}};
    int sz = sizeof(s)/sizeof(s[0]);
    bubble_sort(s,sz,sizeof(struct Stu),compar_struct);
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%s %d\n",s[i].name,s[i].age);
    }
}
int main()
{
//    test3();
    test4();
    return 0;
}
