#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

inline bool is_power_of_two(unsigned long int num)
{
    return ((num & (num - 1)) == 0);
}

int main()
{
	int N, U, R, I, tU, tR, tI, maior;
	bool pU, pR, pI;

	while(cin >> N && N)
	{
		tU = tR = tI = 0;
		while(N--)
		{
			cin >> U >> R >> I;
			pU = pR = pI = false;

			if(is_power_of_two(U))
			{
				tU++;
				pU = true;
			}

			if(is_power_of_two(R))
			{
				tR++;
				pR = true;
			}

			if(is_power_of_two(I))
			{
				tI++;
				pI = true;
			}

			maior = U;

			if(maior < R)
			{
				maior = R;
			}

			if(maior < I)
			{
				maior = I;
			}

			// Ponto por maior numero
			if(maior == U && pU)
			{
				tU++;
			}
			else if(maior == R && pR)
			{
				tR++;
			}
			else if(maior == I && pI)
			{
				tI++;
			}
		}

		if(tU > tR && tU > tI)
		{
			cout << "Uilton" << endl;
		}
		else if(tR > tU && tR > tI)
		{
			cout << "Rita" << endl;
		}
		else if(tI > tU && tI > tR)
		{
			cout << "Ingred" << endl;
		}
		else
		{
			cout << "URI" << endl;
		}
	}

	return 0;
}