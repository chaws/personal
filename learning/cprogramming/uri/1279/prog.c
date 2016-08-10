#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char year[BUFSIZ], first = 1, ordinary, leap;
	unsigned long div3;
	long div11;
	int i, len;

	while(scanf("%s", year) != EOF)
	{
		ordinary = 1;
		leap = 0;
		len = strlen(year);
		// int i = 0;
		// for(; i < len; i++)
		// 	printf("year[%i] = %c\n", i, year[i]);
		// printf("year = %s, len = %i\n", year, len);
		(first) ? first = 0 : printf("\n");

		// Leap year
		if(
			(
				// Divisible by 4?
				((year[len - 2] - '0') * 10 + year[len - 1] - '0') % 4 == 0 
				&&
				// Not divisible by 100?
				!(year[len - 1] == '0' && year[len - 2] == '0')
			)
			||
			// Divisible by 400?
			(
				// Which must be divisible by 100
				(year[len - 1] == '0' && year[len - 2] == '0')	
				&&
				// and also be divisible by 4, after dividing by 100
				((year[len - 4] - '0') * 10 + year[len - 3] - '0') % 4 == 0 
			)
		)
		{	
			printf("This is leap year.\n");
			ordinary = 0;
			leap = 1;
		}

		// Festival huluculu
		div3 = div11 = i = 0;
		while(i < len)
		{
			div3 += year[i] - '0';
			div11 += ((i % 2) ? -1 : 1) * (year[i] - '0');
			i++;
		}

		if(
			div3 % 3 == 0
			&&
			(year[len - 1] == '0' || year[len - 1] == '5')
		)
		{
			printf("This is huluculu festival year.\n");
			ordinary = 0;
		}

		//printf("div11 = %i\n", div11);
 		// Festival bukulu
		if(
			leap
			&&
			div11 % 11 == 0
			&&
			(year[len - 1] == '0' || year[len - 1] == '5')
		)
		{
			printf("This is bulukulu festival year.\n");
			ordinary = 0;
		}

		if(ordinary)
		{
			printf("This is an ordinary year.\n");
		}
	}

	return 0;
}