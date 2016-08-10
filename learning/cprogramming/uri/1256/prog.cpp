#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, mod, nums, num;
	bool primeiro_teste;

	cin >> N;

	primeiro_teste = true;
	while(N--)
	{
		map<int, vector<int> > hash;
		cin >> mod >> nums;
		while(nums--)
		{
			cin >> num;
			hash[num % mod].push_back(num);
		}

		if(primeiro_teste)
			primeiro_teste = false;
		else
			cout << endl;

		for(int i = 0; i < mod; i++)
		{
			cout << i << " -> ";
			if(hash[i].size() == 0)
			{
				cout << "\\" << endl;
				continue;
			}

			//sort(hash[i].begin(), hash[i].end());
			for(int j = 0; j < hash[i].size(); j++)
			{
				cout << hash[i].at(j) << " -> ";
			}
			cout << "\\" << endl;
		}
	}

	return 0;
}