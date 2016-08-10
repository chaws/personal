#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	long num;
	long mod;
} el;

el * ela, * elb;
int cmp(const void * a, const void * b)
{
	ela = (el *)a;
	elb = (el *)b;

	if(ela->mod != elb->mod)
	{
		return ela->mod - elb->mod;
	}

	if(ela->num % 2)
	{
		return (elb->num % 2) ? (elb->num - ela->num) : -1;
	}
	else
	{
		return (elb->num % 2) ? 1 : (ela->num - elb->num);
	}
}

int main()
{
	long iN, N, M;
	el nums[10001];

	while(scanf("%li %li", &N, &M) != EOF)
	{
		if(!N && !M)
		{
			printf("0 0\n");
			break;
		}

		iN = 0;
		while(iN < N)
		{
			scanf("%li", &(nums[iN].num));
			// Negative mod for negative numbers
			nums[iN].mod = nums[iN].num % M;
			// printf("%li mod %li = %li\n", nums[iN].num, M, nums[iN].mod);
			iN++;
		}

		qsort(nums, N, sizeof(el), cmp);

		printf("%li %li\n", N, M);
		iN = 0;
		while(iN < N)
		{
			printf("%li\n", nums[iN].num);
			iN++;
		}

	}

	return 0;
}