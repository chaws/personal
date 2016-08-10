#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t1, t2, t3, t4;

	while(cin >> t1 >> t2 >> t3 >> t4)
	{
		cout << ((t1 - 1) + (t2 - 1) + (t3 - 1) + t4) << endl;
	}

	return 0;
}