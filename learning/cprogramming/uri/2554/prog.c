#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{

	int day, month, year, N, iN, D, iD, printed, goNoGo, everyoneOK;

	while(scanf("%d %d", &N, &D) != EOF)
	{
		iD = printed = 0;
		while(iD++ < D)
		{
			scanf("%d/%d/%d", &day, &month, &year);
			iN = 0, everyoneOK = 1;
			while(iN++ < N)
			{
				scanf("%d", &goNoGo);
				everyoneOK &= goNoGo;
			}

			if(!printed && everyoneOK)
			{
				printf("%d/%d/%d\n", day, month, year);
				printed = 1;
			}
		}

		if(!printed)
		{
			printf("Pizza antes de FdI\n");
		}
	}

	return 0;
}
