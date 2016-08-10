#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	string line = "--------------------------------------------------------------------------------";
	int printed;

	printed = 0;
	while(cin >> word)
	{
		if(word == "<br>")
		{
			cout << endl;
			printed = 0;
			continue;
		}

		if(word == "<hr>")
		{
			if(printed > 0)
			{
				printed = 0;
				cout << endl;
			}

			cout << line << endl;
			continue;
		}

		if(printed == 0 && word.size() == 80)
		{
			cout << word << endl;
		}

		if(printed + word.size() + 1 > 80)
		{
			cout << endl;
			printed = 0;
		}

		if(printed)
		{
			cout << ' ';
		}

		cout << word;
		printed += word.size() + 1;
	}

	if(printed)
	{
		cout << endl;
	}

	return 0;
}