#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int T, N;

	while(scf("%d", &T) != EOF)
	{
		if(!T)
			break;
		while(T--)
		{
			scf("%d", &N);
			if(N & 1)
			{
				N--;
				prf("%d\n", N*2 + 1);
			}
			else
			{
				N -= 2;
				prf("%d\n", N*2 + 2);
			}
		}
	}

	return 0;
}
