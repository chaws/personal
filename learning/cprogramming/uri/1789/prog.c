#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * linha = malloc(1600), lixo, * ptr;
	int L, V, ret, maior, nivel;
	size_t read;
	ssize_t len;

	while(scanf("%i", &L) != -1)
	{
		ret = scanf("%c", &lixo);
		read = getline(&linha, &len, stdin);
		ptr = linha, nivel = maior = -1;
		while(L--)
		{
			sscanf(ptr, "%i%n", &V, &read),	ptr += read;
			if(V > maior)
				maior = V, nivel = (V < 10 ? 1: (V < 20 ? 2 : 3));
		}
		printf("%i\n", nivel);
	}

	return 0;
}