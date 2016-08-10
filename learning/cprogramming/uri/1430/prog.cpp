#include <iostream>
#include <string>

using namespace std;

int main()
{
	string compass;
	int corrects, sum, notes['X' + 1];

	notes['W'] = 64;
	notes['H'] = 32;
	notes['Q'] = 16;
	notes['E'] = 8;
	notes['S'] = 4;
	notes['T'] = 2;
	notes['X'] = 1;

	while(cin >> compass)
	{
		if(compass == "*")
		{
			break;
		}

		sum = corrects = 0;
		for(int i = 0; i < compass.size(); i++)
		{
			if(compass[i] == '/')
			{
				if(sum == 64)
				{
					corrects++;
				}

				sum = 0;
				continue;
			}

			sum += notes[compass[i]];
		}
		cout << corrects << endl;
	}

	return 0;
}