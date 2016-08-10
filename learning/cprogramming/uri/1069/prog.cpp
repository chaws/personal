#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int T, diamonds, opening;
	string areia;

	cin >> T;

	while(T--)
	{
		opening = diamonds = 0;
		cin >> areia;
		for(int i = 0; i < areia.size(); i++)
		{
			if(areia[i] == '<')
			{
				opening++;
			}
			else if(areia[i] == '>')
			{
				if(opening > 0)
				{
					diamonds++;
					opening--;
				}
			}
		}

		cout << diamonds << endl;
	}

	return 0;
}