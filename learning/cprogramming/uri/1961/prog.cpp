#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int P, N, ip, ip2;

RESTART:
	while(cin >> P >> N)
	{
		N--;
		cin >> ip2;

		while(N--)
		{
			cin >> ip;
			if(abs(ip2 - ip) > P)
			{
				cout << "GAME OVER" << endl;
				goto RESTART;
			}

			ip2 = ip;
		}

		cout << "YOU WIN" << endl;
	}

	return 0;
}