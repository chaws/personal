#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N;
	double min, max;

	while(scf("%d", &N) != EOF)
	{
		min = N / log(N);
		max = 1.25506 * min;
		prf("%.1f %.1f\n", min, max);
	}

	return 0;
}
