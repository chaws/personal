#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, in, L[10002], il, P[10002], ip, base, power, smallest, lucas, pedro, rodadas[1001];
	long double result;
	char c;

	while(cin >> N)
	{
		lucas = pedro = in = 0;
		while(in++ < N)
		{
			// Set Lucas
			cin >> base >> c >> power;
			for(il = 0; il < power; il++)
			{
				L[il] = base;
			}

			// Set Pedro
			cin >> base >> c;
			for(ip = 0; ip < base; ip++)
			{
				P[ip] = base - ip;
			}

			// Divide P / L, if < 1, then P is smaller
			smallest = (base > power ? power : base);
			ip = il = 0;
			result = 1;
			for(int i = 0; i < smallest; i++, ip++, il++)
			{
				result *= (long double)P[ip] / (long double)L[il];
				//cout << "result = " << result << " * (" << P[ip] << " / " << L[il] << ")" << endl;
			}

			// Finish the rest of the array
			for(int i = il; il < power; il++)
			{
				result = result /(long double) L[il];
				//cout << "result = " << result << " / " << L[il] << endl;
			}

			for(int i = ip; ip < base; ip++)
			{
				result *= (long double)P[ip];
				//cout << "result = " << result << " * " << P[ip] << endl;
			}

			if(result < 1.0)
				lucas++, rodadas[in] = 0;
			else
				pedro++, rodadas[in] = 1;
		}

		if(lucas == pedro)
		{
			cout << "A competicao terminou empatada!" << endl;
		}
		else
		{
			cout << "Campeao: "<< (lucas > pedro ? "Lucas" : "Pedro") << "!" << endl;
		}

		for(in = 1; in <= N; in++)
		{
			cout << "Rodada #"<< in <<": "<< (rodadas[in] == 0 ? "Lucas" : "Pedro") <<" foi o vencedor" << endl;
		}
	}

	return 0;
}