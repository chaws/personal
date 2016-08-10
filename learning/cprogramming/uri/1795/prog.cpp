#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		cout << (long long int)powl(3, N) << endl;
	}

	return 0;
}