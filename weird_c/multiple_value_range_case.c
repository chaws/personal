#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	a = 0 ? : 3;
	switch(a)
	{
		case 0 ... 10:
			printf("between 0 and ten \n");
			break;
		default:
			printf("Out of range \n");
	}
	return 0;
}