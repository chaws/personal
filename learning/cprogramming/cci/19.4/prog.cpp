#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int max(int a, int b)
{
	return (a + b + abs(a - b)) / 2;
}

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		cout << max(a, b) << endl;
	}

	return 0;
}