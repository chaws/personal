#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, factors[6], decimal, rest;

	factors[1] = 1;
	factors[2] = 1 * 2;
	factors[3] = 1 * 2 * 3;
	factors[4] = 1 * 2 * 3 * 4;
	factors[5] = 1 * 2 * 3 * 4 * 5;

	while(cin >> N)
	{
		if(!N)
		{
			break;
		}

		rest = N / 10000, N -= rest * 10000;
		decimal = rest * factors[5];

		rest = N / 1000, N -= rest * 1000;
		decimal += rest * factors[4];

		rest = N / 100, N -= rest * 100;
		decimal += rest * factors[3];

		rest = N / 10, N -= rest * 10;
		decimal += rest * factors[2];

		rest = N;
		decimal += rest * factors[1];

		cout << decimal << endl;
	}

	return 0;
}