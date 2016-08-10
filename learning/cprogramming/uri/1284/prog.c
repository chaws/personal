#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

typedef char word[83];

int cmpWord(const void * a, const void * b)
{
	char * wa = (char *)a;
	char * wb = (char *)b;
	int len = strlen(wa) - strlen(wb);
	int cmp = strncmp(wa, wb, (len > 0 ? strlen(wb) : strlen(wa)));
	return cmp == 0 ? len : cmp;
}

int main(void)
{
	char c;
	int N, iN, count, iword;
	double avg;
	word dictionary[10001] = {0}, * ptr;

	while(scf("%i", &N) != EOF)
	{
		for(iN = 0; iN < N; iN++)
		{
			scf("%s", dictionary[iN]);
		}

		qsort(dictionary, N, sizeof(word), cmpWord);

		avg = 0;
		for(c = 'a', iN = 0; c <= 'z'; c++)
		{
			count = 0;
			if(dictionary[iN][0] != c)
			{
				continue;
			}

			count++;
			ptr = &dictionary[iN][0];
			for(iN < N; iN++)
			{

				if(dictionary[iN][iN])
			}

			avg += count;
			prf("%s\n", dictionary[iN]);
		}

		prf("%.2f\n", avg / N);
	}

	return 0;
}
