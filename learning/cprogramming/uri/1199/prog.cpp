#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	string n;
	//bool first = false;
	char upper['F' + '9'];

	upper['0'] = '0', upper['1'] = '1', upper['2'] = '2',
	upper['3'] = '3', upper['4'] = '4', upper['5'] = '5',
	upper['6'] = '6', upper['7'] = '7', upper['8'] = '8',
	upper['9'] = '9';

	upper['a'] = 'A';
	upper['b'] = 'B';
	upper['c'] = 'C';
	upper['d'] = 'D';
	upper['e'] = 'E';
	upper['f'] = 'F';

	while(cin >> n)
	{
		if(n[0] == '-')
		{
			break;
		}

		// if(!first)
		// {
		// 	cout << endl;
		// }

		if(n.find('x') != string::npos)
		{
			cout << dec << stol(n, nullptr, 0); 
		}
		else
		{
			stringstream ss;
			ss << hex << stol(n);
			n = ss.str();
			for(int i = 0; i < n.size(); i++)
			{
				n[i] = upper[n[i]];
			}

			cout << "0x" << n;
		}
		cout << endl;
		// if(first)
		// {
		// 	first = false;
		// }
	}

	return 0;
}