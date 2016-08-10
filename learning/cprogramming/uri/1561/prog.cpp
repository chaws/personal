#include <iostream>
#include <string>

using namespace std;

int main()
{
	short h, m;
	char les;
	string hora, min;

	while(cin >> h >> les >> m)
	{
		//cout << h << " " << m << endl;

		hora = "|   |                                    |   |";
		min  = "|   |                                    |   |";

		if(h & 1) hora[38] = 'o';
		if(h & 2) hora[28] = 'o';
		if(h & 4) hora[18] = 'o';
		if(h & 8) hora[8] = 'o';

		if(m & 1) min[38] = 'o';
		if(m & 2) min[32] = 'o';
		if(m & 4) min[26] = 'o';
		if(m & 8) min[20] = 'o';
		if(m & 16) min[14] = 'o';
		if(m & 32) min[8] = 'o';
		
		cout << " ____________________________________________" << endl;
		cout << "|                                            |" << endl;
		cout << "|    ____________________________________    |_" << endl;
		cout << "|   |                                    |   |_)" << endl;
		cout << "|   |   8         4         2         1  |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << hora << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |                                    |   |" << endl;
		cout << min << endl;
		cout << "|   |                                    |   |" << endl;
		cout << "|   |   32    16    8     4     2     1  |   |_" << endl;
		cout << "|   |____________________________________|   |_)" << endl;
		cout << "|                                            |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << endl;
	}

	return 0;
}