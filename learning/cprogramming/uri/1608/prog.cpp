#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T, D, I, Ii, B, Bi, precos[100], Q, Qi, item, qtd, menor, preco;

	cin >> T;
	while(T--)
	{
		cin >> D >> I >> B;

		Ii = -1;
		while(++Ii < I) 
			cin >> precos[Ii];

		Bi = -1;
		menor = 1000000000;
		while(++Bi < B)
		{
			cin >> Q;
			Qi = -1;
			preco = 0;
			while(++Qi < Q)
			{
				cin >> item >> qtd;
				preco += precos[item] * qtd;
			}
			if(preco < menor)
				menor = preco;
		}

		cout << (D / menor) << endl;

	}


	return 0;
}