#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
	int N;
	long int total;
	string nome;
	map<string, int> mapa;
	bool primeiro_teste, primeira_arvore;

	cin >> N;
	getline(cin, nome);
	getline(cin, nome);

	primeiro_teste = true;
	while(N--)
	{
		total = 0;
		while(getline(cin, nome))
		{
			if(nome.size() == 0)
				break;
			total++;
			mapa[nome]++;
		}

		if(primeiro_teste)
			primeiro_teste = false;
		else
			cout << endl;

		map<string, int>::iterator it = mapa.begin();
		//primeira_arvore = true
		while(it != mapa.end())
		{
			cout << it->first << " " << setprecision(4) << fixed << (it->second*100/(double)total) << endl;
			it++;
		}
		mapa.clear();
	}

	return 0;
}