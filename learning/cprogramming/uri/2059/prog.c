#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

// p r a sum%2
// 0 0 0 1 -> 1
// 1 0 0 0 -> 1
// 0 0 1 0 -> 1
// 0 0 1 1 -> 1
// 0 1 0 0 -> 1
// 0 1 0 1 -> 1
// 1 0 1 0 -> 1
// 1 0 1 1 -> 1
// 1 1 0 0 -> 1
// 1 1 0 1 -> 1

// 1 0 0 1 -> 2
// 0 0 0 0 -> 2
// 0 1 1 0 -> 2
// 0 1 1 1 -> 2
// 1 1 1 0 -> 2
// 1 1 1 1 -> 2

int main(void)
{
	int  p, j1, j2, r, a, sum_2;

	while(scf("%i %i %i %i %i", &p, &j1, &j2, &r, &a) != EOF)
	{
		sum_2 = (j1 + j2) % 2;
		if(r != a || (r == 0 && p != sum_2))
		{
			prf("Jogador 1 ganha!\n");
		}
		else
		{
			prf("Jogador 2 ganha!\n");
		}
	}

	return 0;
}