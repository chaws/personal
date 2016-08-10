#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int calls;

int fib(int n)
{
	calls++;
	if(n == 0 || n == 1)
	{
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int T, n, f;

	cin >> T;

	while(T--)
	{
		cin >> n;
		calls = 0;
		f = fib(n);
		cout << "fib(" << n << ") = " << --calls << " calls = " << f << endl;
	}

	return 0;
}