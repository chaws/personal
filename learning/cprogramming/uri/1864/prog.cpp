#include <iostream>
#include <string>

using namespace std;

int main()
{
	string citation = "LIFE IS NOT A PROBLEM TO BE SOLVED";
	int N, i;
	while(cin >> N)
	{
		i = 0;
		while(i < N)
		{
			cout << citation[i++];
		}
		cout << endl;
	}
	return 0;
}