#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int i, p, rpm, b;

int main(void)
{
	scf("%i", &p);
	for(i = 1, b = -1; i <= p; i++)
	{
		scf("%i", &rpm);
		if(rpm < b)
		{
			prf("%i\n", i);
			return 0;
		}
		b = rpm;
	}

	prf("0\n");
	return 0;
}
