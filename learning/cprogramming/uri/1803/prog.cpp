#include <iostream>
#include <string>

using namespace std;

int main()
{
	string matrix[4], saida;
	int code, max, F, L;
	while(cin >> matrix[0] >> matrix[1] >> matrix[2] >> matrix[3])
	{
		max = matrix[0].size() - 1;

		F = ((matrix[0][0] - '0') * 1000) + ((matrix[1][0] - '0') * 100) 
		  + ((matrix[2][0] - '0') * 10) + (matrix[3][0] - '0');
		L = ((matrix[0][max] - '0') * 1000) + ((matrix[1][max] - '0') * 100) 
		  + ((matrix[2][max] - '0') * 10) + (matrix[3][max] - '0');

		saida = "";
		for(int i = 1; i < max; i++)
		{
			code = ((matrix[0][i] - '0') * 1000) + ((matrix[1][i] - '0') * 100) 
			  		 + ((matrix[2][i] - '0') * 10) + (matrix[3][i] - '0');
			saida.append(1, (F * code + L) % 257);
		}

		cout << saida << endl;
	}

	return 0;
}