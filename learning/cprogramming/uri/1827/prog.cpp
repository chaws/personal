#include <iostream>
#include <string>

using namespace std;

//int matriz[102][102];

int main()
{
	int N, i, j, start1, middle;
	while(cin >> N)
	{
		start1 = N / 3;
		middle = N / 2;
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)	
			{
				if(i == middle && j == middle)
					//matriz[i][j] = 4;
					cout << 4;
				else if((i >= start1 && i <= N - 1 - start1) && (j >= start1 && j <= N - 1 - start1))
					//matriz[i][j] = 1;
					cout << 1;
				else if(i == j)
					//matriz[i][j] = 2;
					cout << 2;
				else if(i == (N - 1 - j))
					//matriz[i][j] = 3;
					cout << 3;
				else
					//matriz[i][j] = 0;
					cout << 0;
			}
			cout << endl;
		}
		// for(i = 0; i < N; i++)
		// {
		// 	for(j = 0; j < N; j++)	
		// 	{
		// 		cout << matriz[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		cout << endl;
	}
	return 0;
}