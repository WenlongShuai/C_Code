//  03_实现k的n次方
//  k^n     2^3=8


#include <stdio.h>

double numPower(int k,int n)
{
    if(n > 0)
    {
        return numPower(k, n-1)*k;
    }
    else if(n < 0)
    {
        return 1.0/numPower(k, -n);
    }
    else
    {
        return 1.0;
    }
}

int main(int argc, const char * argv[])
{
    int k = 0;
    int n = 0;
    scanf("%d %d",&k,&n);
    double ret = numPower(k, n);
    printf("%lf\n",ret);
    
    return 0;
}
