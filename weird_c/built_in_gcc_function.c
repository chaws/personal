#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	a = 5, b = 5;
	__sync_bool_compare_and_swap(&a, b, 1);
	printf("a = %i\n", a);
	return 0;
}