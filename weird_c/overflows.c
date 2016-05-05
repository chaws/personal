#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int a[10];

	int * b;
	b = malloc(10 * sizeof(int));

	int index = atoi(getenv("SOMEVAR"));
	printf("Trying to acces %i-th position = %i\n", index, b[index]);
	b[index] = 1;

	return 0;
}