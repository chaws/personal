#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, pessoa, anterior, tempo, diff;
	while(cin >> N && N)
	{
		cin >> anterior;
		tempo = 10;
		while(--N)
		{
			cin >> pessoa;
			diff = pessoa - anterior;
			//cout << "diff = " << pessoa << " - " << anterior << " = " << diff << endl;
			tempo += (diff >= 10 ? 10 : diff);
			anterior = pessoa;
		}

		cout << tempo << endl;
	}

	return 0;
}