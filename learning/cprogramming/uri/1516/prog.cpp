#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int N, M, A, B, repeatN, repeatM;
	char img[51][51];
	string line;

	while(1)
	{
		cin >> N >> M;
		if(!N && !M)
			break;

		memset(img, 0, 51 * 51 * sizeof(char));
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> img[i][j];

		cin >> B >> A;
		repeatN = A / N;
		repeatM = B / M;

		for(int i = 0; i < N; i++)
		{
			line = "";
			for (int j = 0; j < M; j++)
				for(int k = 0; k < repeatN; k++)
					line.push_back(img[i][j]);

			for(int k = 0; k < repeatM; k++)
				cout << line << endl;
		}
				
		cout << endl;
	}
	
    return 0;
}