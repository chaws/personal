#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double sqrt3;

double koch(int L)
{
	double area = L*L*sqrt3/4.0;
	return 8*area/5.0;
}

int main()
{
	sqrt3 = sqrt(3);
	int L;

	while(cin >> L)
	{
		cout << setprecision(2) << fixed << koch(L) << endl;
	}

	return 0;
}