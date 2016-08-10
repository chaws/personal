#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned long long int X, Y;

	while(cin >> X >> Y)
	{
		if(X == Y)
		{
			cout << 4 << endl;
			continue;
		}

		if(X % 2 && Y % 2)
		{
			cout << ((X + Y) * 2) << endl;
			continue;
		}

		X += Y;

		if(X % 2)
			cout << (X * 2) << endl;
		else
			cout << X << endl;
	}

	return 0;
}