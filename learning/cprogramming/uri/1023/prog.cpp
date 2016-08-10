#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
	int N, T, consumos[201], pessoas, consumo;
	double total_pessoas, total_consumo, res;
	bool primeiro_teste, primeiro_consumo;

	T = 1;
	primeiro_teste = true;
	while(cin >> N)
	{
		if(!N)
			break;

		total_consumo = total_pessoas = 0.0;
		memset(consumos, 0, (sizeof *consumos) * 201);

		while(N--)
		{
			cin >> pessoas >> consumo;
			consumos[consumo / pessoas] += pessoas;
			total_consumo += consumo, total_pessoas += pessoas;
		}

		if(primeiro_teste)
			primeiro_teste = false;
		else
			cout << endl;

		cout << "Cidade# " << T++ << ":" << endl;
		primeiro_consumo = true;
		for(int i = 0; i < 201; i++)
		{
			if(consumos[i])
			{
				if(primeiro_consumo)
					primeiro_consumo = false;
				else
					cout << " ";
				cout << consumos[i] << "-" << i;
			}
		}
		res = floor((total_consumo / total_pessoas) * 100.0) / 100.0;
		cout << endl << "Consumo medio: " << setprecision(2) << fixed << res << " m3." << endl;
	}

	return 0;
}