#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int N, H, M, O;

	while(scf("%d", &N) != EOF)
	{
		while(N--)
		{
			scf("%d %d %d", &H, &M, &O);
			prf("%02d:%02d - A porta %s!\n", H, M, (O ? "abriu" : "fechou"));
		}
	}

	return 0;
}
