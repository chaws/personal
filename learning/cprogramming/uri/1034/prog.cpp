#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, M, b[26], resp;

	while(cin >> T)
	{
		while(T--)
		{
			cin >> N >> M;

			for(int i = 0; i < N; i++)
			{
				cin >> b[i];
			}

			sort(b, b + N);

			resp = 0;
			while(M)
			{
				N--;
				resp += M / b[N];
				M = M % b[N];
				//cout << "N = " << N << ", M = " << M << ", resp = " << resp << endl;
			}

			cout << resp << endl;
		}
	}

	return 0;
}