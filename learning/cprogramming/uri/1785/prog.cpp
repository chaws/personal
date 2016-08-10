#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int maior[10000], menor[10000];

int maior_numero_com_digitos_de(int X)
{
	stringstream ss;
	ss << setfill('0') << setw (4) << X;
  	string num = ss.str();
	sort(num.rbegin(), num.rend());
	return atoi(num.c_str());
}

int menor_numero_com_digitos_de(int X)
{
	stringstream ss;
	ss << setfill('0') << setw (4) << X;
  	string num = ss.str();
	sort(num.begin(), num.end());
	return atoi(num.c_str());
}

int krapekar(int X) 
{
   int cnt = 0;

   while (X != 6174) 
   {
       int maior = maior_numero_com_digitos_de(X);
       int menor = menor_numero_com_digitos_de(X);

       //cout << "maior = " << maior << ", menor = " << menor << endl;

       X = maior - menor;

		if(X <= 0)
			return -1;

       cnt++;
   }

   return cnt;
}

int main()
{
	int T, iT, X;
	cin >> T;

	while(iT++ < T)
	{
		cin >> X;
		cout << "Caso #" << iT << ": " << krapekar(X) << endl;
	}

	return 0;
}