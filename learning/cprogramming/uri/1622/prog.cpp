#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int N, K;
char pos[101];
string lamps;

inline void swapUntil(int clicks)
{
	// do a one time loop
	for(int i = 1; clicks--;)
	{
		lamps[i - 1] = (lamps[i - 1] == 'x' ? 'o' : 'x');
		i = (K + i) % N;
		if(i == 0)
			i = N;
	}
}

int main()
{
	int Q, M;
	string original;
	while(cin >> N >> Q)
	{
		if(!N && !Q)
		{
			break;
		}

		cin >> original;
		while(Q--)
		{
			lamps = original;
			memset(pos, 0, sizeof(char) * 101);
			cin >> K >> M;

			int cicle = 0, i = 1;
			while(1)
			{
				if(pos[i])
					break;
				pos[i] = 1;
				i = (K + i) % N;
				if(i == 0)
					i = N;
				cicle++;
			}

			// inv works like this:
			// if inv == 0
			// 		it means that we should invert all positions within the first cicle
			// else if inv % 2 == 1
			//		it means that all positions should be changed
			// else
			//		it means that all positions should remain the same
			// 
			int inv = M / cicle;

			// cicle is always even
			if(inv == 0)
			{
				swapUntil(M);
			}
			else
			{
				// Change everything
				if(inv % 2)
				{
					swapUntil(cicle);
				}

				// Now, treat the rest of the changes
				int remains = M % cicle;
				swapUntil(remains);
			}

			cout << lamps << endl;
		}
	}

	return 0;
}