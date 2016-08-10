#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long int N;
	while(cin >> N)
	{
		cout << ((N * (N -3)) / 2) << endl;
	}
	return 0;
}