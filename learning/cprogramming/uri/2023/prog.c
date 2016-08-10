#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

typedef struct 
{
	char ori[90], min[90]; // min has all-lower-case ori
	int len;
} Name;

int cmpName(const void *a, const void *b)
{
	Name * n1 = (Name *)a, * n2 = (Name *)b;
	int diff = n1->len - n2->len;
	return strncmp(n1->min, n2->min, (diff > 0 ? n2->len : n1->len));
}

int main(void)
{
	Name l[1001]; // l[0][0] stores the size of l[0]
	int lsize, i;

	lsize = 0;
	while(fgets(l[lsize].ori, 90, stdin))
	{
		l[lsize].len = strlen(l[lsize].ori) - 1;
		l[lsize].ori[ l[lsize].len ] = '\0';
		//prf("'%s' len = %d\n", l[lsize].ori, l[lsize].len);

		if(l[lsize].len == 0)
			break;

		for(i = 0; i < l[lsize].len; i++)
			l[lsize].min[i] = tolower(l[lsize].ori[i]);

		lsize++;
	}

	qsort(l, lsize, sizeof(Name), cmpName);

	prf("%s\n", l[lsize - 1].ori);

	return 0;
}
