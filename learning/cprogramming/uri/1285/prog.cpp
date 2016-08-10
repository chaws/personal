#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool nums[5001] = {false};
	int N, M, total;

	nums[0] = nums[1] = nums[2] = nums[3] = nums[4] =
	nums[5] = nums[6] = nums[7] = nums[8] = nums[9] = true;

	for(int m = 0; m < 5; m++)
		for(int c = 0; c <= 9; c++)
			for(int d = 0; d <= 9; d++)
				for(int u = 0; u <= 9; u++)
				{
					if(
						(m > 0 && (m == c || m == d || m == u || c == d || c == u || d == u)) ||
						(c > 0 && (c == d || c == u || d == u)) ||
						(d > 0 && (d == u))
					)
						continue;
					nums[m*1000 + c*100 + d*10 + u] = true;
				}

	// for(int i = 0; i <= 120; i++)
	// {
	// 	cout << i << "(" << (nums[i] ? "true" : "false") << ") ";
	// }

	while(cin >> N >> M)
	{
		total = 0;
		for(int i = N; i <= M; i++)
			if(nums[i])
				total++;
		cout << total << endl;
	}

	return 0;
}