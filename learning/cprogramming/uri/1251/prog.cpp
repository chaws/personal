#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	string line;
	int chars[150];
	bool primeiro_teste = true;

	while(cin >> line)
	{
		if(primeiro_teste)
			primeiro_teste = false;
		else
			cout << endl;

		memset(chars, 0, (sizeof * chars) * 150);
		for(int i = 0; i < line.size(); i++)
			chars[line[i]]++;

		map<int, vector<int> > mapa;
		for(int i = 32; i <= 128; i++)
			if(chars[i])
				mapa[chars[i]].push_back(i);

		map<int, vector<int> >::iterator it = mapa.begin();
		for(; it != mapa.end(); it++)
		{
			sort(it->second.begin(), it->second.end());
			for(int i = it->second.size() - 1; i > -1; i--)
				cout << it->second.at(i) << ' ' << it->first << endl;
		}
	}

	return 0;
}