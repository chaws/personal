#include <stdio.h>
#include <stdlib.h>

int main()
{
	char buff[BUFSIZ], stop = 0, dict[128];
	size_t bread;
	int i;

	// Populate dictionary
	for(i = 0; i < 128; i++)
		dict[i] = i;

	// ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// AFCDEFGHIFKLMNOFQRFTUFWFYF

	// Exchange 'f' and 'F'
	dict['b'] = dict['j'] = dict['p'] = dict['s'] = dict['v'] = dict['x'] = dict['z'] = 'f';
	dict['B'] = dict['J'] = dict['P'] = dict['S'] = dict['V'] = dict['X'] = dict['Z'] = 'F';

	while(!stop)
	{
		bread = fread(buff, sizeof(char), BUFSIZ, stdin);
		stop = bread != BUFSIZ;
		printf("%c", buff[0]);

		for(i = 1; i < bread; i++)
		{
			//printf("buff = '%c', prev = '%c'\n", buff[i], prev);
			if(dict[ buff[i] ] == 'f' || dict[ buff[i] ] == 'F')
			{
				buff[i] = dict[ buff[i] ];
				if(buff[i - 1] == 'f' || buff[i - 1] == 'F')
				{
					continue;
				}
			}
			
			printf("%c", buff[i]);
		}
	}
	printf("\n");
	return 0;
}