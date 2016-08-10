#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf printf

typedef char word[201];

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
	word words[10000], input, * ptrWord;
	char alph[300] = {0}, c;
	int iPtr;

	// Initialize table
	for(c = 'A'; c <= 'Z'; c++) alph[c] = c + 32; // A(65), a(97)
	for(c = 'a'; c <= 'z'; c++) alph[c] = c;

	ptrWord = &words[0];
	while(scanf("%s", input) != EOF)
	{
		printf("read %s\n", input);
		iPtr = 0;
		for(c = 0; c < strlen(input); c++)
		{
			if(alph[input[c]] == 0)
			{
				printf("found '%c', creating another word\n", alph[input[c]]);
				(*ptrWord)[iPtr] = '\0';
				ptrWord++;
				iPtr = 0;
			}
			else
			{
				printf("found '%c', appending\n", alph[input[c]]);
				(*ptrWord)[iPtr++] = alph[input[c]];
			}
		}

		(*ptrWord)[iPtr] = '\0';
		ptrWord++;
	}

	qsort(words, ptrWord - words, sizeof(word), cmpWord);

	for(c = 0; c < 40; c++)
		printf("word = %s\n", words[c]);

	// for(c = 0; c < ptrWord - words; c++)
	// {
	// 	if(words[c][0])
	// 	printf("%s\n", ptrWord);
	// }

	return 0;
}