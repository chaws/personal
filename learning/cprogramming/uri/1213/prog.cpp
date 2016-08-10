#include <iostream>

using namespace std;

int main()
{
	int N, ones, rest, mod;

	while(cin >> N)
	{
		if(N == 1)
		{
			cout << N << endl;
			continue;
		}

		rest = 10 % N;
		mod = 11 % N;
		for(ones = 2; mod; ones++)
			mod = (mod * rest  + 1) % N;

		cout << ones << endl;
	}

	return 0;
}