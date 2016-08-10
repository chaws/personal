#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct 
{
	double troco;
	int qtd;
} prod;

bool myfunction(prod i, prod j) 
{
	if(i.qtd == j.qtd)
		return (i.troco < j.troco);
	return (i.qtd < j.qtd);
}

int main()
{
	int T, D, N;
	double preco;
	vector<prod> trocos;

	while(cin >> T)
	{
		while(T--)
		{
			cin >> D >> N;
			trocos.clear();

			while(N--)
			{
				cin >> preco;

				if(preco > D)
					continue;

				prod p;
				p.qtd = (int)(D / preco);
				p.troco = D - p.qtd * preco;
				trocos.push_back(p);

				//cout << p.qtd << ", " << p.troco << endl;
			}

			sort(trocos.begin(), trocos.end(), myfunction);
			
			cout << fixed;
			cout << setprecision(2) << trocos[trocos.size() - 1].troco << endl;
		}
	}
	
    return 0;
}