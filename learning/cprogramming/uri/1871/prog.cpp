#include <iostream>
#include <string>

using namespace std;

int main()
{
	string result, newResult;
	int M, N;

	while(cin >> M >> N)
	{
		if(!M && !N)
		{
			break;
		}

		result = to_string(M + N);
		newResult = "";
		for(int i = 0, j = 0; i < result.size(); i++)
			if(result.at(i) != '0')
				newResult.append(1, result.at(i));

		cout << newResult << endl;
	}

	return 0;
}