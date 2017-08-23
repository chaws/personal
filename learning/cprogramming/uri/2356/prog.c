#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

int main(void)
{
	char code[101], res[101], lcode, lres , *pcode;

	while(scf("%s", code) != EOF)
	{
		scf("%s", res);

		pcode = code;

		lcode = strlen(code);
		lres = strlen(res);

		while(lcode >= lres)
		{
			if(!strncmp(pcode, res, lres))
			{
				prf("Resistente\n");
				goto GOON;
			}

			lcode--, pcode++;
		}

		prf("Nao resistente\n");

		GOON:
		;
	}

	return 0;
}
