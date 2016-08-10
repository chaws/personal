#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	string input;
	int T;
	unsigned long int total;
	char times[128];
	
	memset(times, 2, 128);
	times['a'] = times['A'] = 
	times['e'] = times['E'] = 
	times['i'] = times['I'] = 
	times['o'] = times['O'] = 
	times['s'] = times['S'] = 3;

	cin >> T;

	while(T--)
	{
		cin >> input;
		total = 1;

		for(int i = 0; i < input.size(); i++)
		{
			total *= times[input[i]];
		}
		cout << total << endl;
	}

	return 0;
}