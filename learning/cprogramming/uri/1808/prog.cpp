#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string grades;
	double avrg;
	int scores[101], numscores;

	while(cin >> grades)
	{
		numscores = 0;
		for(int i = 0; i < grades.size(); i++, numscores++)
		{
			if(grades[i] == '0')
				scores[--numscores] = 10;
			else
				scores[numscores] = grades[i] - '0';
		}

		avrg = 0.0;
		for(int i = 0; i < numscores; i++)
			avrg += scores[i];

		cout << setprecision(2) << fixed << (avrg / (double) numscores) << endl;
	}

	return 0;
}