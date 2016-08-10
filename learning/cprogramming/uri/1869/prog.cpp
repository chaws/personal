#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned long long int N, rest;
	char base32[33] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
	string result;

	while(cin >> N)
	{
		if(!N)
		{
			cout << 0 << endl;
			break;
		}
		
		result = "";
		while(N)
		{
			rest = N % 32;
			N /= 32; 
			result = base32[rest] + result;
		}

		cout << result << endl;
	}

	return 0;
}