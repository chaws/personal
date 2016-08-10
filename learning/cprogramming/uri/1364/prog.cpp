#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, iN, M, iM, changes, smallest;
	string tmp;

	while(cin >> N >> M)
	{
		if(!N && !M)
			break;

		string emoticons[N], phrases[M];

		iN = iM = -1;
		while(++iN < N)
		{
			cin >> emoticons[iN];
			cout << emoticons[iN] << endl;
		}
		getline(cin, phrases[0]);

		while(++iM < M)
		{
			getline(cin, phrases[iM]);
		}

		changes = 0;
		for(iM = 0; iM < M; iM++)
		{
			for(int l = 0; l < phrases[iM].size();)
			{
				smallest = 200;
				for(iN = 0; iN < N; iN++)
				{
					if(emoticons[iN].size() <= (phrases[iM].size() - l) && 
					   phrases[iM].compare(l, emoticons[iN].size(), emoticons[iN]) == 0)
					{
						if(emoticons[iN].size() < smallest)
						{
							//cout << emoticons[iN] << endl;
							smallest = emoticons[iN].size();
						}
					}
				}

				if(smallest != 200)
				{
					changes++;
					l += smallest;
				}
				else
					l++;
			}
		}

		cout << changes << endl;
	}

	return 0;
}