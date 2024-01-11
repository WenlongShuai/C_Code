//  BC27_计算球体体积
//  给定一个球体的半径，然后根据半径求出体积
//  公式：4/3*PIR^3     PI=3.1415926


#include <stdio.h>
#define PI 3.1415926

int main(int argc, const char * argv[])
{
    float r = 0.0;
    float v = 0.0;
    scanf("%f",&r);
    v = 4.0/3*PI*r*r*r;
    printf("%.3lf\n",v);
    return 0;
}
