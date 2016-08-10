#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, read;
	char word[10001];

	while(scf("%d", &N) != EOF)
	{
		while(N--)
		{
			scf("%s%n", word, &read);
			prf("%.2f\n", --read/100.0);
		}
	}

	return 0;
}
