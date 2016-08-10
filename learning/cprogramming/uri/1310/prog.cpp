#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, C, vals[51], max, acc;

	while(cin >> N)
	{
		if(!N)
			break;

		cin >> C;

		if(N == 1)
		{
			cin >> acc;
			if(acc > C)
				cout << (acc - C) << endl;
			else
				cout << 0 << endl;
			continue;
		}

		for(int i = 0; i < N; i++)
		{
			cin >> vals[i];
		}

		max = -1;
		for(int i = 0; i < N; i++)
		{
			acc = vals[i];

			if(acc > C && (acc - C) > max)
				max = acc - C;

			//cout << "i = " << i << endl;
			for(int j = i + 1, c = 2; j < N; j++, c++)
			{
				acc += vals[j];
				//cout << "j = " << j << ", vals = " << vals[j] << ", acc = " << acc << ", C = " << (c*C) << endl;

				if(acc >= c*C && (acc - c*C) > max)
					max = acc - c*C;

				//cout << "max = " << max << endl;
			}
		}

		if(max > 0)
			cout << max << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}