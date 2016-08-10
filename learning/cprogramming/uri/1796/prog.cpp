#include <iostream>
#include <string>

using namespace std;

int main()
{
	int Q, votes[2], in;

	cin >> Q;

	votes[0] = votes[1] = 0;
	while(Q--)
	{
		cin >> in;
		votes[in]++;
	}

	cout << (votes[0] > votes[1] ? 'Y' : 'N') << endl;

	return 0;
}