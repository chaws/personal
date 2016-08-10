#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int a, b, r, q;
	while(cin >> a >> b)
	{
		if(!a || a == -0)
		{
			cout << "0 0" << endl;
			continue;
		}

		q = (b < 0 ? ceil((float)a / (float)b) : floor((float)a / (float)b));
		r = a - b * q;
		
		cout << q << ' ' << r << endl;
	}

	return 0;
}