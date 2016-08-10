#include <iostream>
#include <string>

using namespace std;

typedef struct 
{
	string name;
	string oddsEvens;
} player;

int main()
{
	int N, n1, n2;
	player p[2];

	while(cin >> N)
	{
		while(N--)
		{
			cin >> p[0].name >> p[0].oddsEvens;
			cin >> p[1].name >> p[1].oddsEvens;
			cin >> n1 >> n2;

			if((n1 + n2) % 2)
			{
				if(p[0].oddsEvens == "IMPAR")
				{
					cout << p[0].name << endl;
				}
				else
				{
					cout << p[1].name << endl;
				}
			}
			else
			{
				if(p[0].oddsEvens == "PAR")
				{
					cout << p[0].name << endl;
				}
				else
				{
					cout << p[1].name << endl;
				}
			}
		}
	}

	return 0;
}