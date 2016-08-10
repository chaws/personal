#include <iostream>
#include <string>

using namespace std;

long int quadrados(int n)
{
	if(n == 0 || n == 1)
		return n;
	if(n == 2)
		return 5;
	return (n*2 + n + quadrados(n - 1));
}

int main()
{
	int N;
	while(cin >> N)
	{
		if(!N)
			break;

		cout << quadrados(N) << endl;
	}
	return 0;
}