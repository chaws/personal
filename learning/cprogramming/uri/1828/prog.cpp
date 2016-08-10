#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int T, i;
	string she, raj;
	map<string, int> pesos;

	pesos["tesoura-papel"] = 1,   pesos["papel-tesoura"] = -1;
	pesos["tesoura-lagarto"] = 1, pesos["lagarto-tesoura"] = -1;
	pesos["papel-pedra"] = 1,     pesos["pedra-papel"] = -1;
	pesos["papel-Spock"] = 1,     pesos["Spock-papel"] = -1;
	pesos["pedra-lagarto"] = 1,   pesos["lagarto-pedra"] = -1;
	pesos["pedra-tesoura"] = 1,   pesos["tesoura-pedra"] = -1;
	pesos["lagarto-Spock"] = 1,   pesos["Spock-lagarto"] = -1;
	pesos["lagarto-papel"] = 1,   pesos["papel-lagarto"] = -1;
	pesos["Spock-tesoura"] = 1,   pesos["tesoura-Spock"] = -1;
	pesos["Spock-pedra"] = 1,     pesos["pedra-Spock"] = -1;

	while(cin >> T)
	{
		i = 0;
		while(i++ < T)
		{
			cout << "Caso #" << i << ": ";
			cin >> she >> raj;
			if(she == raj)
			{
				cout << "De novo!" << endl;
			}
			else
			{
				cout << (pesos[she + '-' + raj] == 1 ? "Bazinga!" : "Raj trapaceou!") << endl;
			}

		}
	}

	return 0;
}