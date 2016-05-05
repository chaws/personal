#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, i;

	num = 5, i = 0;

	while(--num && ++i) printf("running...\n");

	printf("num = %i, i = %i \n", num, i);

	return 0;
}