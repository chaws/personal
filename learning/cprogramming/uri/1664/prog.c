#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define prf printf
#define scf scanf
#define ischar(c) (alph[(int)*c])

char * BS = "BULLSHIT";

int wcount;

typedef struct 
{
	char * str;
	int len;
} word;

// alphabet
char alph[300] = {0};

// finds the new word, and set the start and end to pos
inline int nextw(word * w, word * next)
{
	//prf("w->len = %d\n", w->len); // PRINT_DEBUG
	if(!w->len)
		return -1;

	char * c = w->str;
	int i = 0, len = 0;

	// Get the start
	while(i < w->len && !ischar(c))
		i++, c++;

	// Got to the end and didn't find anybody
	if(i == w->len)
		return -1;

	next->str = c;

	// If this word is upper case BULLSHIT, DO NOT lowercase
	// be careful with cases like
	// "this is a line of exampe SHIT\n"
	// "secondw examples the BULL\n"
	// Since all words are lowercased 
	if(strncmp(BS, c, 8) == 0)
	{
		// prf("is %s\n", BS);// PRINT_DEBUG
		c += 8, len += 8;
	}
	else
	{
		// prf("is not %s\n", BS); // PRINT_DEBUG
		// Get the end
		while(i < w->len && ischar(c))
			*c = tolower(*c), i++, c++, len++;
	}

	// Move current cursor
	w->len -= c - w->str;
	w->str = c;

	next->len = len;
	return 0;
}

int cmpw(const void * a, const void * b)
{
	word * w1 = (word *)a, * w2 = (word *)b;
	return strncmp(w1->str, w2->str, (w1->len < w2->len ? w1->len : w2->len));
}

int main(void)
{
	char buff[200];
	int len, iwords, i;
	unsigned long totalw = 0, totalg = 0; // total number of words and games
	int *pprimes, primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 0};

	// game contains 'words' ordered
	word words[510], tmpw, * currw;

	// init alphabet
	alph['A'] = alph['B'] = alph['C'] = alph['D'] = alph['E'] = alph['F'] = alph['G'] = alph['H'] = alph['I'] = alph['J'] = alph['K'] = alph['L'] = alph['M'] = alph['N'] = alph['O'] = alph['P'] = alph['Q'] = alph['R'] = alph['S'] = alph['T'] = alph['U'] = alph['V'] = alph['W'] = alph['X'] = alph['Y'] = alph['Z'] = 
	alph['a'] = alph['b'] = alph['c'] = alph['d'] = alph['e'] = alph['f'] = alph['g'] = alph['h'] = alph['i'] = alph['j'] = alph['k'] = alph['l'] = alph['m'] = alph['n'] = alph['o'] = alph['p'] = alph['q'] = alph['r'] = alph['s'] = alph['t'] = alph['u'] = alph['v'] = alph['w'] = alph['x'] = alph['y'] = alph['z'] = 1;

	// End of the buffer
	iwords = 0;
	while(fgets(buff, 101, stdin))
	{
		len = strlen(buff);
		tmpw.str = buff;
		tmpw.len = len;
		while(!nextw(&tmpw, words + iwords))
		{
			if(!strncmp(BS, words[iwords].str, words[iwords].len))
			{
				totalg++;

				// Avoid cases starting with BULLSHIT
				if(iwords < 1)
					continue;

				totalw++;
				currw = words;
				//prf("processing %d words!\n", iwords); // PRINT_DEBUG
				qsort(words, iwords, sizeof(word), cmpw);
				for(i = 1; i < iwords; i++)
				{
					if(cmpw(currw, words + i))
					{
						totalw++, currw = words + i;
						//prf("different\n"); // PRINT_DEBUG
					}
				}

				//prf("totalw = %lu, totalg = %lu\n", totalw, totalg);// PRINT_DEBUG

				iwords = 0;
			}
			else
			{
				//words[iwords].str[words[iwords].len] = 0; // PRINT_DEBUG
				//prf("word[%d] = '%s'\n", iwords, words[iwords].str); // PRINT_DEBUG
				iwords++;
			}
		}
	}

	// Find the minimum fraction
	pprimes = primes;
	while(*pprimes && *pprimes <= totalw && *pprimes <= totalg)
	{
		if(totalg % *pprimes || totalw % *pprimes)
			pprimes++;
		else
			totalg /= *pprimes, totalw /= *pprimes;
	}

	prf("%lu / %lu\n", totalw, totalg);

	return 0;
}
