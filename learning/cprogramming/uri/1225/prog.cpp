#include <iostream>
#include <string>

using namespace std;

int main()
{
	long int N, iN, coral[10001], total, med;

	while(cin >> N)
	{
		iN = -1;
		total = 0;
		while(++iN < N)
		{
			cin >> coral[iN];
			total += coral[iN];
		}

		if(total % N)
		{
			cout << -1 << endl;
			continue;
		}

		iN = -1;
		med = total / N;
		total = 1;
		while(++iN < N)
		{
			if(coral[iN] < med)
			{
				total += med - coral[iN];
			}
		}

		cout << total << endl;
	}

	return 0;
}