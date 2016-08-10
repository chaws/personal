#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	double D, VF, VG;
	while(cin >> D >> VF >> VG)
		cout << ((12.0 / VF) >= (sqrt(144.0 + D * D) / VG) ? "S" : "N") << endl; 

	return 0;
}