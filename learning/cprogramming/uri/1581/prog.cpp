#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, K, iK;
	string curr, old;
	bool keep;

	cin >> N;

	while(N--)
	{
		cin >> K >> old;

		keep = true;
		iK = 1;
		while(iK++ < K)
		{
			cin >> curr;
			//cout << "curr = " << curr << ", old = " << old << endl;
			if(keep)
			{
				if(curr.compare(old))
				{
					keep = false;
					old = "ingles";
				}
				else
				{
					old = curr;
				}
			}
		}

		cout << old << endl;
	}

	return 0;
}