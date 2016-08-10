#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int N, p, qtd;

	float prices[1006], total;
	prices[1001] = 1.50;
	prices[1002] = 2.50;
	prices[1003] = 3.50;
	prices[1004] = 4.50;
	prices[1005] = 5.50;

	while(cin >> N)
	{
		total = .0;
		while(N--)
		{
			cin >> p >> qtd;
			total += prices[p] * qtd;
		}

		cout << fixed << setprecision(2) << total << endl;
	}

	return 0;
}