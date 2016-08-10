#include <iostream>

using namespace std;

int main()
{
	int T, iT, N, seq, maior_seq, P, maior_P;

	cin >> T;
	iT = 0;

	while(iT++ < T)
	{
		cin >> N;

		maior_seq = 1, maior_P = -1;

		// 5 6 6 6 5 5 6 6 6 7 7
		for(int iN = 0; iN < N; iN++)
		{
			cin >> P;

			if(P > maior_P)
			{
				maior_P = P;
				seq = 1;
				maior_seq = 1;
			}
			else if(P == maior_P)
			{
				seq++;
			}
			else
			{
				seq = 0;
			}

			if(seq > 1)
			{
				maior_seq = seq;
			}
		}

		cout << "Caso #" << iT << ": " << maior_seq << endl;
	}

	return 0;
}