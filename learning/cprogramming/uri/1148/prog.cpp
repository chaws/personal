#include <iostream>
#include <map>
#include <vector>
#include <climit>

using namespace std;

int N, mapa[502][502];

int shortestPath(int A, int B, map<int, int> &invalids)
{
	if(invalids[B])
		return -1;

	map<int, int> ways;
	int distance = -1, smallest = MAX_INT, smallestIndex = -1;

	for(int i = 0; i < N; i++)
	{
		if(invalids[i])
		{
			continue;
		}

		if(mapa[A][i] > -1)
		{
			if(mapa[A][i] < smallest)
			{
				smallest = mapa[A][i];
				smallestIndex = i;
			}
		}
	}

	return -1;
	// invalids[A] = 1; something like this
}

int main()
{
	int E, A, B, X, K, D;

	while(cin >> N >> E)
	{
		if(!N && !E)
		{
			return 0;
		}

		map<int, map<int, int> > inputed;
		while(E--)
		{
			cin >> A >> B >> X;
			inputed[A][B] = X;
		}

		// Clean the other positions and identify the ones in their countries
		for(int y = 1; y <= N; y++)
		{
			for(int x = 1; x <= N; x++)
			{
				if(inputed[y][x])
				{
					mapa[y][x] = (inputed[x][y] ? 0 : inputed[y][x]);
				}
				else
				{
					mapa[y][x] = -1;
				}
			}
		}

		// for(int y = 1; y <= N; y++)
		// {
		// 	for(int x = 1; x <= N; x++)
		// 	{
		// 		cout << mapa[y][x] << ' ';
		// 	}
		// 	cout << endl;
		// }

		cin >> K;
		while(K--)
		{
			cin >> A >> B;

			invalids.clear();

			invalids[A] = 1;
			D = shortestPath(A, B, invalids);
		}

		cout << endl;
	}

	return 0;
}