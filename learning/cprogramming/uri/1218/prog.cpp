#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main()
{
	int N, M, F, num, cases = 1;
	string line, masc_or_fem;
	char lixo;

	while(cin >> N)
	{
		if(cases > 1)
			cout << endl;
		scanf("%c", &lixo);

		getline(cin, line);

		stringstream ss(line);

		F = M = 0;
		while(ss >> num >> masc_or_fem)
		{
			if(num == N)
			{
				if(masc_or_fem == "F")
				{
					F++;
				}
				else
				{
					M++;
				}
			}
		}

		cout << "Caso " << cases++ << ":" << endl;
		cout << "Pares Iguais: " << (F + M) << endl;
		cout << "F: " << F << endl;
		cout << "M: " << M << endl;
	}

	return 0;
}