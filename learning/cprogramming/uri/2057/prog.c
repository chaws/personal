#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int S, T, F, ans;

	while(scf("%i %i %i", &S, &T, &F) != EOF)
	{
		ans = (((S + T) % 24) + F) % 24;
		prf("%i\n", (ans < 0 ? ans + 24 : ans));
	}

	return 0;
}