//  05_计算1/1-1/2+1/3..-1/100



#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    float ret = 0;
    for(i=1;i<=100;i++)
    {
        ret = ret+pow((-1), i+1)*(1.0/i);
    }
    printf("%f\n",ret);
    return 0;
}
