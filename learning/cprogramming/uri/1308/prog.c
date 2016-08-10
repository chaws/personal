#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long T, N;
	scanf("%llu", &T);

	while(T--)
	{
		scanf("%llu", &N);
		if(N < 2)
		{
			printf("%llu\n", N);
			continue;
		}

		printf("%llu\n", (unsigned long long)((sqrt((8 * N) + 1) - 1.0) * 0.5));
	}


	return 0;
}