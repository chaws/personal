#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int N, first, spaces, starts;

	while(cin >> N)
	{
		first = N / 2 + 1;

		for(int i = 0; i < first; i++)
		{
			spaces = first - i - 1;
			while(spaces--)
			{
				cout << " ";
			}

			starts = ((i + 1) * 2) - 1;
			while(starts--)
			{
				cout << "*";
			}

			cout << endl;
		}

		spaces = first - 1;
		while(spaces--)
		{
			cout << " ";
		}

		cout << "*" << endl;

		spaces = first - 2;
		while(spaces--)
		{
			cout << " ";
		}
		cout << "***" << endl << endl;
	}

	return 0;
}