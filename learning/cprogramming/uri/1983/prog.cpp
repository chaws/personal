#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, matricula, maiorm;
	float nota, maiorn;

	while(cin >> N)
	{
		maiorn = -1.0;
		while(N--)
		{
			cin >> matricula >> nota;

			if(nota > maiorn)
			{
				maiorm = matricula, maiorn = nota;
			}
		}

		if(maiorn >= 8.0)
			cout << maiorm << endl;
		else
			cout << "Minimum note not reached" << endl;
	}

	return 0;
}