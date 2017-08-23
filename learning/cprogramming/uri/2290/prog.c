#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf
typedef int num_type;

int cmp(const void * num1, const void * num2)
{
	num_type n1 = *(num_type *)num1, n2 = *(num_type *)num2;
	return (n1 == n2 ? 0 : (n1 > n2 ? 1 : -1));
}

int main(void)
{
	num_type * nums = malloc(10001 * sizeof(num_type)), prev;
	int num, inum, counter;
	// prf("[DEBUG] size of nums = %d\n", sizeof(nums));

	while(scf("%d", &num))
	{
		// printf("[DEBUG] num = %d\n", num);
		if(!num)
			break;

		inum = 0;
		while(inum < num)
		{
			scf("%d", &nums[inum]);
			// printf("[DEBUG] nums[%d] = %ld\n", inum, nums[inum]);
			inum++;
		}

		qsort(nums, num, sizeof(num_type), cmp);
		nums[num] = (num_type)-1;

		inum = 1;
		counter = 1;
		while(inum <= num)
		{
			if(nums[inum] == nums[inum - 1])
			{
				counter++, inum++;
				continue;
			}

			if(counter & 1)
			{
				prf("%d ", nums[inum - 1]);
			}

			counter = 1, inum++;
		}
		prf("\n");
	}

	return 0;
}
