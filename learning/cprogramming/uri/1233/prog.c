#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	long n, in, l, s;

	while(scf("%ld", &n) != EOF)
	{
		prf("for %ld\n",n);
		for(in = 2; in < n / 2; in++)
		{
			//printf("%ld\n", in);
			// l = (1 + n * in) % n;
			// if(l == 1)
			// {
			// 	printf("r = %ld: %ld\n", in, l);
			// 	s = in / in
			// }
		}
	}

	return 0;
}
