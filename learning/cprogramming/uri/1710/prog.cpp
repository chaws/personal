#include <iostream>
#include <string>
#include <climits>
#include <math.h>

using namespace std;

#define MAX_PLANOS 501
#define A 0
#define B 1
#define C 2
#define D 3
#define TOTAL 4

int main()
{
	int M, iM, N, iN, X, Y, Z, iMenor, maior;
	long int ponto, menor, difference;
	int planos[MAX_PLANOS][5];

	while(cin >> M >> N)
	{
		iM = -1;
		while(++iM < M)
		{
			cin >> planos[iM][A] >> planos[iM][B] >> planos[iM][C] >> planos[iM][D];
			planos[iM][TOTAL] = 0;
		}

		iN = -1;
		while(++iN < N)
		{
			cin >> X >> Y >> Z;

			iM = -1, iMenor = -1, menor = LONG_MAX;
			while(++iM < M)
			{
				ponto = planos[iM][A] * X + planos[iM][B] * Y + planos[iM][C] * Z;
				//cout << "ponto = " << ponto << endl;

				if(ponto < planos[iM][D])
				{
					continue;
				}
				
				difference = ponto - planos[iM][D];

				if(difference < menor)
				{
					menor = difference;
					iMenor = iM;
				}
			}

			if(iMenor > -1)
			{
				planos[iMenor][TOTAL]++;
			}
		}


		maior = iM = -1;
		while(++iM < M)
		{
			if(maior < planos[iM][TOTAL])
			{
				maior = planos[iM][TOTAL];
			}
		}

		cout << maior << endl;
	}

	return 0;
}