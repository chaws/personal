#include <iostream>

using namespace std;

int main()
{
	string rows[3], x = "xxx", o = "ooo";
	char champ;

	while(cin >> rows[0] >> rows[1] >> rows[2])
	{
		cout << rows[0] << endl << rows[1] << endl << rows[2] << endl;

		// There's 8 possibilities to win a tic-tac-toe
		champ = '-';
		for(int i = 0; i < 3; i++)
		{
			// Check rows
			if(rows[i] == x || rows[i] == o)
			{
				champ = rows[i][0];
				break;
			}

			// Check columns
			if(
				(rows[0][i] == 'x' && rows[1][i] == 'x' && rows[2][i] == 'x') || 
				(rows[0][i] == 'o' && rows[1][i] == 'o' && rows[2][i] == 'o')
			)
			{
				champ = rows[0][i];
				break;
			}
		}

		if(champ != '-')
		{
			cout << "Champ is " << champ << "!" << endl;
			continue;
		}

		// Check Diagonals
		if((rows[1][1] == 'x' && 
				((rows[0][0] == 'x' && rows[2][2] == 'x') || (rows[0][2] == 'x' && rows[2][0] == 'x'))) || 

			(rows[1][1] == 'o' && 
				((rows[0][0] == 'o' && rows[2][2] == 'o') || (rows[0][2] == 'o' && rows[2][0] == 'o')))
		)
		{
			champ = rows[1][1];
			cout << "Champ is " << champ << "!" << endl;
		}
		else
		{
			cout << "No champ!" << endl;
		}

	}

	return 0;
}