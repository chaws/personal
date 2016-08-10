#include <iostream>
#include <string>

using namespace std;

int main()
{
	string dollar, cents;
	int start, end;

	while(cin >> dollar >> cents)
	{
		start = dollar.size() % 3;
		end = dollar.size() - 3;

		cout << "$";

		for(int i = 0; i < start; i++)
		{
			cout << dollar[i];
		}

		if(start && dollar.size() > 3)
		{
			cout << ",";
		}

		for(int i = start, c = 1; i < end; i++, c++)
		{
			cout << dollar[i];
			if(c % 3 == 0)
			{
				cout << ",";
			}
		}

		for(int i = end; i < dollar.size(); i++)
		{
			cout << dollar[i];
		}

		cout << ".";

		if(cents.size() == 1)
		{
			cout << "0";
		}

		cout << cents << endl;

	}

	return 0;
}