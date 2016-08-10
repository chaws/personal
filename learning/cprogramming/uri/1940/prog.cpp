#include <iostream>

using namespace std;

int main()
{
	int J, R, p, maxJ, maxI;

	while(cin >> J >> R)
	{
		int jogs[501] = {0};
		for(int i = 0; i < (J * R); i++)
		{
			cin >> p;
			jogs[i % J] += p;

			//cout << "Adding " << p << " to player " << (i % J) << endl;
		}

		maxJ = 0;
		maxI = J;
		for(int i = 0; i < J; i++)
		{
			if(jogs[i] >= maxJ)
				maxJ = jogs[i], maxI = i + 1;
		}

		cout << maxI << endl;
	}

	return 0;
}