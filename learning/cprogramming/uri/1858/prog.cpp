#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, T[101], iN, smallest, iT, algoz;

	while(cin >> N)
	{
		smallest = 21;
		iN = 0;
		algoz = 0;
		while(iN++ < N)
		{
			cin >> iT;
			if(iT < smallest)
			{
				smallest = iT;
				algoz = iN;
			}
		}

		cout << algoz << endl;
	}

	return 0;
}