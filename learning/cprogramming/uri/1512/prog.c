#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

// Greatest Common Divisor
long gcd(long a, long b)
{
	if(b == 0 || a == b)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main(void)
{
	long n, a, b, d, tota, totb, totab;

	while(scf("%ld %ld %ld", &n, &a, &b) != EOF)
	{
		if(!(n | a | b))
			break;

		d = gcd(a, b);
		tota = n / a;
		totb = n / b;
		totab = n / ((a * b) / d);
		//prf("totab = %ld, d = %ld\n", totab, d);

		prf("%ld\n", tota + totb - totab);
	}

	return 0;
}
