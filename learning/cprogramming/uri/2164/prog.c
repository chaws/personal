#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define prf printf
#define scf scanf

int main(void)
{
	int n;
	double sqrt5 = sqrt(5.0);
	scf("%d", &n);
	prf("%.1lf\n", (pow((1 + sqrt5)/2.0, n) - pow((1 - sqrt5)/2.0, n)) / sqrt5);
	return 0;
}
