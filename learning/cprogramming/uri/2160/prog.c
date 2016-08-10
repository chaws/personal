#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

int main(void)
{
	char * in;
	size_t len;

	while(getline(&in, &len, stdin) != -1)
	{
		for(len = 0; in[len] != '\n' && in[len] != '\0'; len++);
		prf("%s\n", (len <= 80 ? "YES" : "NO"));
		//free(in);
	}

	return 0;
}
