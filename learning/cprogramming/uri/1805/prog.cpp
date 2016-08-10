#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned long long int A, B, R;

	while(cin >> A >> B)
	{
		R = (A + B)*(B - A + 1) / 2;
		cout << R << endl;
	}

	return 0;
}