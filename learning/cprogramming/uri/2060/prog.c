#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, num;

	while(scf("%i", &N) != EOF)
	{
		int divs[6] = {0};
		while(N--)
		{
			scf("%i", &num);
			divs[2] += num % 2 == 0;
			divs[3] += num % 3 == 0;
			divs[4] += num % 4 == 0;
			divs[5] += num % 5 == 0;
		}

		prf("%i Multiplo(s) de 2\n%i Multiplo(s) de 3\n%i Multiplo(s) de 4\n%i Multiplo(s) de 5\n", divs[2], divs[3], divs[4], divs[5]);
	}

	return 0;
}
