#include <iostream>
#include <string>

using namespace std;

int main()
{
	string number;
	int num, b1, b2;

	while(cin >> number)
	{
		b1 = b2 = 0;
		for(int i = 1; i <= 9; i++)
		{
			num = number[i - 1] - '0';
			b1 += num * i;
			b2 += num * (10 - i);
			//cout << "b1 = " << b1 << ", b2 = " << b2 << endl;
		}

		b1 = b1 % 11;
		b2 = b2 % 11;

		if(b1 == 10)
		{
			b1 = 0;
		}

		if(b2 == 10)
		{
			b2 = 0;
		}
		cout << number[0];
		cout << number[1];
		cout << number[2];
		cout << '.';
		cout << number[3];
		cout << number[4];
		cout << number[5];
		cout << '.';
		cout << number[6];
		cout << number[7];
		cout << number[8];
		cout << '-';
		cout << b1 << b2 << endl;
	}

	return 0;
}