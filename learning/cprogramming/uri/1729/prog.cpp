#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	int N, T, iN, h, m, s, mm, ss;
	double D, avg;
	string track;
	bool skip;

	while(cin >> N >> D)
	{
		while(cin >> T)
		{
			printf("%3d: ", T);

			iN = 0;
			h = m = s = 0;
			skip = false;

			while(iN++ < N)
			{
				cin >> track;

				if(skip)
				{
					continue;
				}

				if(track[0] == '-')
				{
					skip = true;
				}

				h += track[0] - '0';
				m += ((track[2] - '0') * 10) + (track[3] - '0');
				s += ((track[5] - '0') * 10) + (track[6] - '0');

			}
			
			if(skip)
			{
				cout << "-";
			}
			else
			{ 
				avg = ((h * 60) + m + (s / 60.0)) / D;
				mm = avg / 1;
				ss = (avg - mm) * 60;

				if((avg - mm) >= 0.99)
				{
					mm++;
					ss = 0;
				}

				printf("%d:%02d min/km", mm, ss);
			}

			cout << endl;
		}
	}

	return 0;
}