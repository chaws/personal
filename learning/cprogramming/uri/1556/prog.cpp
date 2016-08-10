#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> perform(string s)
{
	map<string, int> returned, appended;

	if(s.size() == 1)
	{
		//cout << "Adding 1: " << s << endl;
		returned[s] = 1;
		return returned;	
	}

	returned = perform(s.substr(1));
	string c = s.substr(0, 1);

	// Iterate over, addin the "c" to the beginning
	map<string, int>::iterator it;
	for(it = returned.begin(); it != returned.end(); it++)
	{
		//cout << "Adding 2: " << (c + it->first) << endl;
		appended[c + it->first] = 1;
	}
	
	//cout << "Adding 1.5: " << c << endl;
	returned[c] = 1;
	returned.insert(appended.begin(), appended.end());

	return returned;
}

int main()
{
	string str;

	while(cin >> str)
	{
		// Build keys
		// Ex: ABCD -> will be: A, AB, ABC, ABCD, AC, ACD, AD, B, BC, BCD, BD, C, CD, D
		map<string, int> keys = perform(str);

		map<string, int>::iterator it;
		for(it = keys.begin(); it != keys.end(); it++)
		{
			cout << it->first << endl;
		}
		cout << endl;
	}

	return 0;
}