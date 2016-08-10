#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int jornada[1000001];

int main()
{
	long long int N, total, roubados;
	int in, estrelas;
	vector<int> visitados;

	while(cin >> N)
	{
		visitados.clear();

		estrelas = in = roubados = total = 0;
		while(in++ < N)
		{
			cin >> jornada[in];
			total += jornada[in];
		}

		in = 1;
		while(0 < in && in <= N)
		{
			visitados.push_back(in);

			if(!jornada[in])
			{
				break;
			}

			roubados++;

			// Go left or right
			jornada[in]--;
			if((jornada[in] + 1) % 2)
				in++;
			else
				in--;
		}

		vector<int>::iterator it;
		sort(visitados.begin(), visitados.end());
		it = unique(visitados.begin(), visitados.end());
		estrelas = distance(visitados.begin(), it);

		if(!estrelas)
		{
			estrelas = 1;
		}

		cout << estrelas << ' ' << (total - roubados) << endl;
	}
	return 0;
}