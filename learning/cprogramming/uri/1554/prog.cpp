#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	pair<int, int> pares[55];
	int C, N, imenor;
	double menor, d;

	while(cin >> C)
	{
		while(C--)
		{
			cin >> N;
			cin >> pares[0].first >> pares[0].second;
			for(int i = 1; i <= N; i++)
				cin >> pares[i].first >> pares[i].second;

			menor = 1420 * 2840;
			imenor = N;
			for(int i = N; i > 0; i--)
			{
				d = sqrt((pares[i].first - pares[0].first)*(pares[i].first - pares[0].first) + 
						 (pares[i].second - pares[0].second)*(pares[i].second - pares[0].second));
				//cout << "i = " << i << ", d = " << d << endl;
				if(d <= menor)
					menor = d, imenor = i;
			}

			cout << imenor << endl;
		}
	}

	return 0;
}