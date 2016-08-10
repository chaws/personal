#include <stdio.h>

int main()
{
	double A, B, C;

	while(scanf("%lf %lf %lf", &A, &B, &C) != EOF)
	{
		if(A + B < C || A + C < B || B + C < A)
		{
			printf("-1.000\n");
			continue;
		}
		printf("%.3lf\n", (A+B+C)/2.0);
	}

	return 0;
}