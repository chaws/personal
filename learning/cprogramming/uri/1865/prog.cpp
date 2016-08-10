#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, force;
	string name;
	while(cin >> N)
	{
		while(N--)
		{
			cin >> name >> force;
			cout << (name == "Thor" ? 'Y' : 'N') << endl;
		}
	}
	return 0;
}