#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	a = 0 ? : 3;
	printf("a = %i\n", a);
	return 0;
}