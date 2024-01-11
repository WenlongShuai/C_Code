//  BC11_StudentInfo
//输入一个学生的学号以及3科成绩（C语言、数学、英语），在屏幕上输出该生的学号以及3科成绩。成绩四舍五入保留两位小数

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num = 0;
    double c_score = 0.0;
    double m_score = 0.0;
    double e_score = 0.0;
    
    //输入学号以及3科成绩
    scanf("%d;%lf,%lf,%lf",&num,&c_score,&m_score,&e_score);
    
    //输出
    printf("The each subject socre of No. %d is %.2lf, %.2lf, %.2lf.\n",num,c_score,m_score,e_score);
    
    return 0;
}
