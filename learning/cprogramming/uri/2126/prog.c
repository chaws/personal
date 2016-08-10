#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

int main(void)
{
	char N1[15], N2[35], * pN2, nmatches, pmatch, n1len, n2len;
	unsigned long i = 0;

	while(scf("%s %s", N1, N2) != EOF)
	{
		nmatches = pmatch = 0;
		n1len = strlen(N1);
		n2len = strlen(N2);
		// prf("N1 = %s, N2 = %s\n", N1, N2);
		pN2 = N2;
		while(pN2 + n1len <= &N2[n2len])
		{
			if(!strncmp(N1, pN2, n1len))
				nmatches++, pmatch = (pN2 - N2) + 1, pN2 += n1len;
			else
				pN2++;
		}

		memset(N1, 0, 15);
		memset(N2, 0, 35);

		prf("Caso #%ld:\n", ++i);
		if(nmatches)
			prf("Qtd.Subsequencias: %d\nPos: %d\n\n", nmatches, pmatch);
		else
			prf("Nao existe subsequencia\n\n");
	}

	return 0;
}
