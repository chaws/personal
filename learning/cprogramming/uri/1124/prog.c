#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define prf printf
#define scf scanf

int main(void)
{
	int L, C, R1, R2;
	double d, d1, d2, sqrt2;

	sqrt2 = sqrt(2.0);

	while(scanf("%d %d %d %d", &L, &C, &R1, &R2) != EOF)
	{
		if(!L && !C && !R1 && !R2)
			exit(0);

		d1 = (R1 * sqrt2) - R1; // Distance between corner and circle 1
		d2 = (R2 * sqrt2) - R2; // Distance between corner and circle 2

		R1 <<= 1; // R1 * 2
		R2 <<= 1; // R2 * 2

		d = sqrt(L*L + C*C); // Rectangle diagonal

		//prf("d = %.2lf, R1 + d1 + R2 + d2 = %.2lf\n", d, R1 + d1 + R2 + d2);
		prf("%c\n", ((R1 + d1 + R2 + d2) - d <= 0.04 ? 'S' : 'N'));
	}
	return 0;
}
