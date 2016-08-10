#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, M;
	char action[10];
	while(scf("%i %i", &N, &M) != EOF)
	{
		scf("%s", action);
		(action[0] == 'f' ? N++, N++, N-- : (N > 0 ? N-- : 1));
	}
	prf("%i\n", N);
	return 0;
}
