#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, M, c[10001] = {0};

	c[2 + 2] = c[2 + 5]  = c[2 + 10]  = c[2 + 20]  = c[2 + 50]  = c[2 + 100] = 
	           c[5 + 5]  = c[5 + 10]  = c[5 + 20]  = c[5 + 50]  = c[5 + 100] = 
	                       c[10 + 10] = c[10 + 20] = c[10 + 50] = c[10 + 100] = 
	                                    c[20 + 20] = c[20 + 50] = c[20 + 100] = 
	                                                 c[50 + 50] = c[50 + 100] = 
	                                                              c[50 + 100] = 1;

	while(scf("%d %d", &N, &M) != EOF)
	{
		if((N | M) == 0)
			break;
		prf("%s\n", (c[M - N] ? "possible" : "impossible"));
	}
	return 0;
}
