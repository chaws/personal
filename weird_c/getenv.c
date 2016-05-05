#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("PATH is %s\n", getenv("PATH"));
	return 0;
}