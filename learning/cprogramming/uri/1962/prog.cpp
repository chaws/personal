#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, anos;

	while(cin >> N)
	{
		while(N--)
		{
			cin >> anos;
			anos -= 2015;
			if(anos < 0)
			{
				anos *= -1;
				cout << anos << " D.C." << endl;
			}
			else
			{
				cout << ++anos << " A.C." << endl;
			}
		}
	}

	return 0;
}