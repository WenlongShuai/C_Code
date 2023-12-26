//static关键字 ------- 声明一个静态变量
//1.静态局部变量
//2.静态全局变量
//3.静态函数


//静态局部变量
//1.静态变量在预编译的时候执行，且在生命周期内只执行一次
//2.定义静态局部变量时，编译器则在内存的静态区分配内存
//#include <stdio.h>
//
//void Test()
//{
//    //如果定义的局部变量a的值为非静态变量
//    //这段程序则输出  2 2 2 2 2 2 2 2 2 2
////    int a = 1;
////    a++;
////    printf("%d ",a);
//
//    //如果定义的局部变量a的值为静态变量
//    //这段程序则输出  2 3 4 5 6 7 8 9 10 11
//    static int a = 1;
//    a++;
//    printf("%d ",a);
//
//}
//
//int main(int argc, const char * argv[])
//{
//    int i = 0;
//    while(i < 10)
//    {
//        Test();
//        i++;
//    }
//    return 0;
//}


//静态全局变量
//1.静态全局变量只能在自己的源文件中使用，不能在工程下的其他源文件中使用
//#include <stdio.h>
//extern int flag;  //声明 globalStaticTest.c 文件中的全局变量flag
//int main()
//{
//    printf("%d\n",flag);
//    return 0;
//}


//静态函数
//1.静态函数的使用跟静态全局变量使用类似

//#include <stdio.h>
//
//extern int Add(int,int);
//
//int main()
//{
//    int a = 20;
//    int b = 30;
//    int r = Add(a,b);
//    printf("%d\n",r);
//    return 0;
//}
