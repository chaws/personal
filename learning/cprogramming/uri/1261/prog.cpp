#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int M, N;
	long int total, valor;
	string palavra;
	map<string, long int> dict;

	while(cin >> M >> N)
	{
		while(M--)
		{
			cin >> palavra >> valor;
			dict[palavra] = valor;
		}

		while(N--)
		{
			total = 0;
			while(true)
			{
				cin >> palavra;
				if(palavra[0] == '.')
					break;
				total += dict[palavra];
			}
			cout << total << endl;
		}
		dict.clear();
	}

	return 0;
}