#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int R1, X1, Y1, R2, X2, Y2;
	double D;

	while(cin >> R1 >> X1 >> Y1 >> R2 >> X2 >> Y2)
	{
		if(R2 > R1)
		{
			cout << "MORTO" << endl;
			continue;
		}
			
		D = sqrt((X2 - X1)*(X2 - X1) + (Y2 - Y1)*(Y2 - Y1));
		if(D > (R1 + R2))
		{
			cout << "MORTO" << endl;
			continue;
		}

		if(R1 < (D + R2))
		{
			cout << "MORTO" << endl;
			continue;
		}

		cout << "RICO" << endl;
	}

	return 0;
}