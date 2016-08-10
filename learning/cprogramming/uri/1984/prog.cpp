#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;
	string num;
	while(cin >> num)
	{
		i = num.size();
		while(i--)
			cout << num[i];
		cout << endl;
	}
	return 0;
}