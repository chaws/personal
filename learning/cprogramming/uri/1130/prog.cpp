#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10000

int main()
{
	std::ios::sync_with_stdio(false);

	int N, i, dist, curr;
	char tab[MAX + 10], lastTreeBits;
	bool mariaJoga;

	tab[0] = '-';
	tab[1] = '-';

	while(cin >> N)
	{
		if(!N)
			break;

		tab[N] = '-';
		tab[N + 1] = '-';
		mariaJoga = true;
		lastTreeBits = 0;

		i = 0;
		while(i < N)
		{
			curr = i + 2;
			cin >> tab[curr];

			// Check vitoria instantanea
			if(mariaJoga)
			{
				lastTreeBits |= (tab[curr] == 'X' ? 1 : 0);
				lastTreeBits &= 7; // clean everything after first three bits

				if(i > 1)
				{
					if( lastTreeBits == 3 // .XX
					||	lastTreeBits == 5 // X.X
					|| 	lastTreeBits == 6 // XX.
					)
					mariaJoga = false;
				}
			}
			i++;
		}

		// Ve se a maria ja ganhou
		if(!mariaJoga)
			goto FIM;

		// Confirma nas pontas
		if(tab[2] != tab[3] && tab[3] == tab[4] && tab[4] == 'X') // .XX
			goto FIM;

		mariaJoga = true;
		for(i = 2; i < N; i++)
		{
			if(tab[i] == 'X')
			{
				continue;
			}

			// Check if it's safe to play
			if(
				tab[i - 1] != 'X' && tab[i + 1] != 'X' 
			&&	tab[i - 2] != 'X' && tab[i + 2] != 'X'
			)
			{
				tab[i] = 'X';
				mariaJoga = !mariaJoga;
			}
		}

	FIM:
		cout << (mariaJoga ? "S" : "N") << endl;
	}

    return 0;
}
