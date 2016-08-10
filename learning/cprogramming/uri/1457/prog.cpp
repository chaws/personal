#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int T, N;
	string K;
	unsigned long long int fact[101][21];

	for(int k = 1; k <= 20; k++)
	{
		for(int n = 1; n <= 100; n++)
		{
			if(n - k > 0)
			{
				fact[n][k] = n * fact[n - k][k];
				//cout << "N = " << n << ", K = " << k << " = " << fact[n][k] << endl;
				if(fact[n][k] > 1e18)
					break;
			}
			else
				fact[n][k] = n;
		}
	}

	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		cout << fact[N][K.size()] << endl;
	}
	
    return 0;
}