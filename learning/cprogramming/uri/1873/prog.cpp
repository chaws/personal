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
	pesos["papel-spock"] = 1,     pesos["spock-papel"] = -1;
	pesos["pedra-lagarto"] = 1,   pesos["lagarto-pedra"] = -1;
	pesos["pedra-tesoura"] = 1,   pesos["tesoura-pedra"] = -1;
	pesos["lagarto-spock"] = 1,   pesos["spock-lagarto"] = -1;
	pesos["lagarto-papel"] = 1,   pesos["papel-lagarto"] = -1;
	pesos["spock-tesoura"] = 1,   pesos["tesoura-spock"] = -1;
	pesos["spock-pedra"] = 1,     pesos["pedra-spock"] = -1;

	while(cin >> T)
	{
		i = 0;
		while(i++ < T)
		{
			cin >> raj >> she;
			if(she == raj)
			{
				cout << "empate" << endl;
			}
			else
			{
				cout << (pesos[she + '-' + raj] == 1 ? "sheldon" : "rajesh") << endl;
			}

		}
	}

	return 0;
}