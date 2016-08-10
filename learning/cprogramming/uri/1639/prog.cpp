#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string num;
	int a, qtd;

	while(cin >> num)
	{
		if(num == "0")
		{
			break;
		}

		map<int, int> qtds;

		a = stoi(num);

		while(!qtds[a])
		{
			qtds[a]++;

			a *= a;
			a = a - (a / 1000000)*1000000;
			a /= 100; 
		}

		cout << qtds.size() << endl;
	}

	return 0;
}