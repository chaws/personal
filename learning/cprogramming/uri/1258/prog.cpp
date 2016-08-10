#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	string nome;
	string cor;
	string tamanho;
} camisa;

bool comparar(const camisa &c1, const camisa &c2)
{
	if(c1.cor[0] < c2.cor[0])
		return true;
	else if(c1.cor[0] > c2.cor[0])
		return false;

	if(c1.tamanho[0] > c2.tamanho[0])
		return true;
	else if(c1.tamanho[0] < c2.tamanho[0])
		return false;

	if(c1.nome.compare(c2.nome) < 0)
		return true;

	return false;
}

istream& operator>>(istream &is, camisa& c)
{
	getline(is, c.nome);
	is >> c.cor >> c.tamanho;
	return is;
}

ostream& operator<<(ostream &os, camisa&  c)
{
	os << c.cor << ' ' << c.tamanho << ' ' << c.nome;
	return os;
}

int main()
{
	int N;
	vector<camisa> camisas;
	camisa c;
	bool firstPrinted = false;

	while(cin >> N)
	{
		if(!N)
			break;

		camisas.clear();

		if(!firstPrinted)
			firstPrinted = true;
		else
			cout << endl;

		while(N--)
		{
			getline(cin, c.nome);
			cin >> c;
			camisas.push_back(c);
		}

		sort(camisas.begin(), camisas.end(), comparar);

		for(int i = 0; i < camisas.size(); i++)
		{
			cout << camisas[i] << endl;
		}
	}

	return 0;
}