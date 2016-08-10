#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double a, b;
	while(cin >> a >> b)
	{
		cout << fixed << setprecision(2) << ((b / a) - 1) * 100.0 << '%' << endl;
	}
	return 0;
}