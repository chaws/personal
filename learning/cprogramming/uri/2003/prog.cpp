#include <iostream>
#include <string>

using namespace std;

int main()
{
	int h, m, horario = 8 * 60;
	char comma;

	while(cin >> h >> comma >> m)
	{
		m += h * 60 + 60;

		cout << "Atraso maximo: " << (m > horario ? m - horario : 0) << endl;
	}

	return 0;
}