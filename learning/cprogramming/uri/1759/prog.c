#include <stdio.h>

int main()
{
	int ho, i;
	scanf("%i", &ho);
	for(i = 0; i < ho; i++)
	{
		printf("Ho");
		if(i == ho - 1)
			printf("!");
		else
			printf(" ");
	}
	printf("\n");
	return 0;
}