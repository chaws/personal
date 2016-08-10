#include <iostream>
#include <string>

using namespace std;

int trail0(int N)
{
	int zeros = 0, divisor, five = 5;

	do{
		divisor = N / five;
		zeros += divisor;
		five *= 5;
	}while(divisor);

	return zeros;
}

int main()
{
	int N;
	while(cin >> N)
	{
		cout << trail0(N) << endl;
	}

	return 0;
}