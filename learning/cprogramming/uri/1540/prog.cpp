#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int N, A1, V1, A2, V2;

	cin >> N;

	while(N--)
	{
		cin >> A1 >> V1 >> A2 >> V2;

		A2 -= A1;
		V2 -= V1;

		char buff[32];

		sprintf(buff, "%f", (V2 / (double)A2));

		for(int i = 0; i < strlen(buff); i++)
		{
			if(buff[i] == '.')
			{
				buff[i] = ',';
				buff[i+3] = '\0';
				break;
			}
		}

		printf("%s\n", buff);
	}

	return 0;
}