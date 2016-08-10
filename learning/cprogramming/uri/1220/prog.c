#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int cmp(const void *a, const void *b)
{
	return *(double *)b - *(double *)a;
}

int main(void)
{
	long int n, i, min;
	double d[1001], total, changed;

	while(scf("%ld", &n))
	{
		if(!n)
			break;

		i = 0;
		total = 0.0;
		while(i < n)
		{
			scf("%lf", d + i);
			d[i] *= 100;
			total += d[i];
			i++;
		}

		qsort(d, i, sizeof(double), cmp);

		//prf("total = %lf / %ld = %lf\n", total, n, total / n);// PRINT_DEBUG
		total /= n;
		changed = 0;

		min = i = 0;
		while(d[i] > total)
		{
			changed += total;
			min += d[i];
			//prf("i = %ld, d[i] = %lf\n", i, d[i]);// PRINT_DEBUG
			//prf("changed = %lf\n", changed);// PRINT_DEBUG
			//prf("min = %ld\n", min); // PRINT_DEBUG
			i++;
		}

		//prf("changed(%lf) - min(%ld) = %lf\n", changed, min, (changed - min));// PRINT_DEBUG

		prf("$%.2lf\n", (changed - min)/100.0);
	}

	return 0;
}
