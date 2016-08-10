#include <iostream>
#include <string>

using namespace std;

int main()
{
	int C, N;
	while(cin >> C)
	{
		while(C--)
		{
			cin >> N;
			cout << N % 2 << endl;
		}
	}
	return 0;
}