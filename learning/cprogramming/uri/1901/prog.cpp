#include <iostream>

using namespace std;

int main()
{
	int N, f[201][201], x, y, K[1001] = {0}, e;

	while(cin >> N)
	{
		for(y = 1; y <= N; y++)
			for (x = 1; x <= N; ++x)
				cin >> f[y][x];

		for(int i = 0; i < 2*N; i++)
		{
			cin >> y >> x;
			K[ f[y][x] ] = 1;
		}

		e = 0;
		for(int i = 1; i <= 1000; i++)
			if(K[i])
			{
				e++;
				K[i] = 0;	
			}
		cout << e << endl;
	}

	return 0;
}