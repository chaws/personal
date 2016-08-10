#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, corridas;


	while(cin >> n)
	{
		if(!n) break;

		corridas = 0;
		while(n > 1)
		{
			n = (n / 3) + (n % 3 ? 1 : 0);
			corridas += n;
		}
		cout << corridas << endl;
	}

	return 0;
}