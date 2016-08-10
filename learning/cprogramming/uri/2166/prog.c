#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

double divide(int keep)
{
	return keep ? (1.0 / (2.0 + divide(--keep))) : 0;
}

int main(void)
{
	int n;
	while(scf("%d", &n) != EOF)
	{
		prf("%.10lf\n", 1.0 + divide(n));
	}

	return 0;
}