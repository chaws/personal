#include <iostream>
#include <string>

using namespace std;

int main()
{
	int F1, F2;

	while(cin >> F1 >> F2)
	{
		F1 = F2 - F1;

		if(F2 >= 97)
			cout << "cheia" << endl;
		else if(F2 <= 2)
			cout << "nova" << endl;
		else if(F1 < 0)
			cout << "minguante" << endl;
		else
			cout << "crescente" << endl;
	}

	return 0;
}