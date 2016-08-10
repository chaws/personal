#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int num; // the number
	int pos; // the original position
} special_numer;

int cmp(const void * a, const void * b)
{
	special_numer * sa = (special_numer *)a; 
	special_numer * sb = (special_numer *)b; 

	if(sa->num == sb->num)
		return sa->pos - sb->pos;
	return sa->num - sb->num;
}

int main(void)
{

	int N, iN, M, iM, K, iK, V, num, inum, lastV;
	special_numer * ptrArr;

	while(scanf("%i %i", &N, &M) != EOF)
	{
		special_numer arr[1000001] = {0};
		for(iN = 0; iN < N; iN++)
		{
			scanf("%i", &num);

			arr[iN].num = num;
			arr[iN].pos = iN + 1;
		}

		qsort(arr, N, sizeof(special_numer), cmp);
		arr[N].num = -1;

		// for(iN = 0; iN < N; iN++)
		// {
		// 	printf("%i - %i\n", arr[iN].num, arr[iN].pos);
		// }

		lastV = iN = 0;
		for(iM = 0; iM < M; iM++)
		{
			scanf("%i %i", &K, &V);
			
			// Find V
			ptrArr = arr;
			while(ptrArr < &arr[N] && ptrArr->num < V)
			{
				ptrArr++;
			}

			if(ptrArr == &arr[N])
			{
				printf("0\n");
				continue;
			}

			// V found, need too look for its position
			K--;
			if((*(ptrArr + K)).num == V)
			{
				printf("%i\n", (*(ptrArr + K)).pos);
			}
			else
			{
				printf("0\n");
			}
		}
	}

	return 0;
}