#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
	int N, M, P;
	string prod;
	double valor, total;
	map<string, double> feira;

	cin >> N;

	while(N--)
	{
		cin >> M;
		while(M--)
		{
			cin >> prod >> valor;
			feira[prod] = valor;
		}

		cin >> P;
		total = 0.0;
		while(P--)
		{
			cin >> prod >> valor;
			total += feira[prod] * valor;
		}

		cout << "R$ " << setprecision(2) << fixed << total << endl;
		feira.clear();
	}

	return 0;
}