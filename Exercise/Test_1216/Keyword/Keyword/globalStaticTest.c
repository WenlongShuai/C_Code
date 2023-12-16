//用于测试静态全局变量和静态函数

//使用全局变量以及静态全局变量
//int flag = 1;   //定义一个flag的全局变量。  此全局变量可以在该工程任何源文件中使用
static int flag = 1;   //定义一个flag的静态全局变量。  此静态全局变量只可以在该源文件中使用


//使用全局函数以及静态全局函数
//int Add(int x,int y)
//{
//    return x+y;
//}

static int Add(int x,int y)
{
    return x+y;
}


