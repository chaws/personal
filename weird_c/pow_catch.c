#include <stdio.h>
// #include <stdlib.h>
#include <math.h>

int main(void)
{
    CASE1:
    {
        double num = 10 ^ 3700;
        double exponent = 10 ^ 37;
        double ans;
        ans = pow(num, exponent);
        printf("ans = %lf, num = %lf, exponent = %lf\n", ans, num, exponent);
    }

    CASE2:
    {
        float num=1.004;
        int exponent=3;
        double ans;
        ans=pow(num,exponent);
        printf("ans = %lf, num = %lf, exponent = %lf\n", ans, num, exponent);
    }
  
    return 0;
}
