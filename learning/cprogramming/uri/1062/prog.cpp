#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	long int N, iN, vagao, comb_len, prev;
	vector<long int> comb;
	bool primeiro_teste;

	primeiro_teste = true;
	while(cin >> N)
	{
		if(!N)
			break;
		
		while(true)
		{
			comb.clear();
			iN = 0;
			primeiro_teste = true;
			while(iN++ < N)
			{
				cin >> vagao;
				if(!vagao)
					break;
				comb.push_back(vagao);
			}

			if(comb.size() == 0)
			{
				cout << endl;
				break;
			}

			comb_len = comb.size();
			vector<bool> arriving(N + 1);
			prev = comb[0];
			arriving[prev] = true;
			for(long int i = 1; i < comb_len; i++)
			{
				if(comb[i] < prev)
				{
					for(long int j = prev - 1; j > comb[i]; j--)
					{
						if(!arriving[j])
						{
							cout << "No" << endl;
							goto NOT_POSSIBLE;
						}
					}
				}

				arriving[comb[i]] = true;
				prev = comb[i];
			}

			cout << "Yes" << endl;

		NOT_POSSIBLE:
			if(primeiro_teste)
				primeiro_teste = false;
			else
				cout << endl;
		}
	}

	return 0;
}