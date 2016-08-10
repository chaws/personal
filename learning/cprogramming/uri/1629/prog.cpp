#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, digits[2], digit;
	size_t len;
	string k;

	while(cin >> N)
	{
		if(!N)
			break;

		while(N--)
		{
			cin >> k;
			len = k.size();
			digit = digits[0] = digits[1] = 0;

			for(int i = 0; i < len; i++)
				digits[i % 2] += k[i] - '0';

			for(int i = 0; i < 2; i++)
				while(digits[i])
					digit += digits[i] % 10, digits[i] /= 10;
				
			cout << digit << endl;
		}
	}

	return 0;
}