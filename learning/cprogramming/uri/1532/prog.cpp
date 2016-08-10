#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char dist[31][1001];
	int N, V;
	long int D;

	memset(dist, 0, 31 * 1001 * sizeof(char));

	// Fill holes it can reach
	dist[1][1] = 1;
	dist[2][2] = 1;
	dist[2][4] = 1;
	dist[2][5] = 1;

	// fill distances
	for(int i = 3; i <= 30; i++)
	{
		D = 0;
		for(int k = i; k > 0; k--)
		{
			for(int j = 0; j < k; j++)
			{
				D += k;
				if(D > 1000) break;

				dist[i][D] = 1;
				//cout << "Filling dist[" << i << "][" << D << "]" << endl;
			}
			if(D > 1000) break;
		}
	}


	while(cin >> N >> V)
	{
		if(!N && !V)
			break;

		for(int i = 1; i <= V; i++)
		{
			if(dist[i][N])
			{
				cout << "possivel" << endl;
				goto NEXT;
			}
		}

		cout << "impossivel" << endl;

	NEXT:
		;
	}
	return 0;
}