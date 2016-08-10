#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	int N, x, semiC, triangles, l1, l2;
	int X[100001];
	
	ios::sync_with_stdio(false);
	while(cin >> N)
	{
		memset(X, 0, sizeof(int) * (N + 1));
		x = triangles = 0;
		while(x < N)
		{
			cin >> X[x];

			if(x > 0)
				X[x] += X[x - 1];

			x++;
		}

		if(X[N - 1] % 3)
		{
			cout << 0 << endl;
			continue;
		}

		semiC = X[N - 1] / 3;

		l1 = l2 = 0;
		for(x = 0; X[x] + 2*semiC <= X[N - 1]; x++)
		{
			// First line
			while(X[l1] < X[x] + semiC)
				l1++;

			// Second line
			while(X[l2] < X[x] + 2*semiC)
				l2++;

			if(X[l1] == X[x] + semiC && X[l2] == X[x] + 2*semiC)
				triangles++;
		}

		cout << triangles << endl;
	}

	return 0;
}