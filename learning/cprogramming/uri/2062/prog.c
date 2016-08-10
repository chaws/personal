#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, len;
	char w[21], first;

	while(scf("%d", &N) != EOF)
	{
		first = 1;
		while(N--)
		{
			scf("%s%n", w, &len);
			w[len] = 0;
			len--;

			if(len == 3 && ((w[0] == 'O' && w[1] == 'B') || (w[0] == 'U' && w[1] == 'R')))
				w[2] = 'I';

			if(first)
				first = 0;
			else
				prf(" "), first = 0;
			prf("%s", w);
		}
		prf("\n");
	}
	return 0;
}
