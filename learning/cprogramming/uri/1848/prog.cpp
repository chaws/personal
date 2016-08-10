#include <iostream>
#include <string>

using namespace std;

int main()
{
	string caw2, piscada;
	int finished, num[3], counter;

	num[0] = num[1] = num[2] = counter = finished = 0;
	while(finished < 3)
	{
		cin >> piscada;
		if(piscada == "caw")
		{
			cout << counter << endl;
			counter = 0;
			cin >> caw2;
			finished++;
		}
		else
		{
			if(piscada[0] == '*')
			{
				counter += 4;
			}
			if(piscada[1] == '*')
			{
				counter += 2;
			}
			if(piscada[2] == '*')
			{
				counter += 1;
			}
		}
	}

	return 0;
}