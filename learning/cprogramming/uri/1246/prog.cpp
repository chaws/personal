#include <iostream>

using namespace std;

int est[1001], comps[10000], P, C;

bool fit(int comp)
{
	for(int i = 0, j; i <= C - comp; i++)
	{
		if(est[i] == 0)
		{
			// check if it fits
			for(j = 0; j < comp; j++)
				if(est[j + i])
					goto NEXT;

			if(j == comp)
			{
				for(j = 0; j < comp; j++)
					est[j + i] = P;
				return true;
			}
		}

		NEXT:
			;
	}

	return false;
}

int main()
{
	int N, profit;
	char ev;

	while(cin >> C >> N)
	{
		for(int i = 0; i < C; i++)
			est[i] = 0;

		profit = 0;
		while(N--)
		{
			cin >> ev >> P;
			if(ev == 'C')
			{
				cin >> comps[P];
				//cout << "chegando " << P << ": ";
				if(fit(comps[P]))
					profit++;
				// else
				// 	cout << " Nao";

				//cout << "Cabeu!" << endl;
			}
			else
			{
				// Remove
				//cout << "removendo " << P << endl;
				int i;
				for(i = 0; i < C; i++)
					if(est[i] == P)
						break;

				for(int j = 0; j < comps[P]; j++)
				{
					est[j + i] = 0;
				}
			}

			// for(int i = 0; i < C; i++)
			// {
			// 	cout << "est[" << i << "] = " << est[i] << endl;
			// }
		}

		cout << (profit * 10) << endl;
	}

	return 0;
}