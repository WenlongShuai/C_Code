//  BC25_计算体重指数
//  BMI指数（身体质量指数）：体重公斤数/身高的平方


#include <stdio.h>

int main(int argc, const char * argv[])
{
    float weight = 0.0;  //体重
    float height = 0.0;  //身高
    float BMI = 0.0;
    scanf("%f %f",&weight,&height);
    BMI = weight/(height*height/10000);
    printf("%.2f\n",BMI);
    
    return 0;
}
