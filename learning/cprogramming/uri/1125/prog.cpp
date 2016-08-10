#include <iostream>
#include <string>

using namespace std;

int main()
{
	int G, Gi, P, Pi, S, Si, K, Ki;
	int grids[101][101], pilotos[101], maior, ponto;
	bool first;

	while(cin >> G >> P)
	{
		if(!G && !P)
		{
			break;
		}

		Gi = 0; while(Gi++ < G)
		{
			Pi = 0; while(Pi++ < P)
			{
				cin >> grids[Gi][Pi];
			}
		}

		cin >> S;
		Si = 0; while(Si++ < S)
		{
			Pi = 0; while(Pi++ < P)
				pilotos[Pi] = 0;
			maior = -1;

			cin >> K;
			Ki = 0; while(Ki++ < K)
			{
				cin >> ponto;
				Gi = 0; while(Gi++ < G)
				{
					Pi = 0; while(Pi++ < P)
					{
						if(grids[Gi][Pi] == Ki)
						{
							pilotos[Pi] += ponto;
							if(pilotos[Pi] > maior)
								maior = pilotos[Pi];
							break;
						}
					}
				}
			}

			first = true;
			Pi = 0; while(Pi++ < P)
			{
				if(pilotos[Pi] == maior)
				{
					if(first)
						first = false;
					else
						cout << ' ';
					cout << Pi;
				}
			}
			cout << endl;
		}
	}

	return 0;
}