#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, in, corretos, resp;

	while(cin >> N)
	{
		in = 5;
		corretos = 0;
		
		while(in--)
		{
			cin >> resp;
			if(resp == N)
				corretos++;
		}

		cout << corretos << endl;
	}

	return 0;
}