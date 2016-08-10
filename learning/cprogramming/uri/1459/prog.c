#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf
#define CONV(ptr) ((interval *)ptr)
#define BIG(a,b) ((b > a ? a = b : 0))
#define SMALL(a,b) ((b < a ? a = b : 0))

typedef struct
{
	int a, b;
} interval;

int cmp(const void * cmpa, const void * cmpb)
{
	int tmp = CONV(cmpa)->a - CONV(cmpb)->a;
	return (tmp ? tmp : CONV(cmpa)->b - CONV(cmpb)->b);
}

int main(void)
{
	unsigned int N, iN, pics;
	interval * inttemp, ints[1000001];

	while(scf("%d", &N) != EOF)
	{
		for(iN = 0; iN < N; iN++)
			scf("%d %d", &ints[iN].a, &ints[iN].b);

		qsort(ints, N, sizeof(interval), cmp);

		iN = pics = 1;
		inttemp = ints;
		while(iN < N)
		{
			ints[iN].a > inttemp->b ? 
				inttemp = &ints[iN], pics++:
				BIG(inttemp->a, ints[iN].a), SMALL(inttemp->b, ints[iN].b);
			iN++;
		}

		prf("%d\n", pics);
	}

	return 0;
}
