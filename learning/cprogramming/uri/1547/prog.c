#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{
	int N, QT, S, i, num, lowest, lowest_i, tmp;
	char keepgoing;

	scanf("%i", &N);

	while(N--)
	{
		scanf("%i %i", &QT, &S);
		keepgoing = 0;
		lowest = INT_MAX;

		for(i = 0; i < QT; i++)
		{
			scanf("%i", &num);

			if(keepgoing)
				continue;

			if(num == S)
			{
				printf("%i\n", i + 1);
				keepgoing = 1;
			}
			else
			{
				tmp = abs(S - num);
				if(tmp < lowest)
				{
					lowest = tmp;
					lowest_i = i;
				}
			}
		}

		if(keepgoing)
			continue;

		printf("%i\n", lowest_i + 1);
	}

	return 0;
}