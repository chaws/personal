#include <iostream>
#include <string>

using namespace std;

int main()
{
	int d1, d2, d3;
	string mood, happy = ":)", sad = ":(";

	while(cin >> d1 >> d2 >> d3)
	{
		if(d2 < d1 && d3 >= d2)
			mood = happy;
		else if(d2 > d1 && d3 <= d2)
			mood = sad;
		else if(d2 > d1 && d3 > d2 && (d3 - d2 < d2 - d1))
			mood = sad;
		else if(d2 > d1 && d3 > d2 && (d3 - d2 >= d2 - d1))
			mood = happy;
		else if(d2 < d1 && d3 < d2 && (d2 - d3 < d1 - d2))
			mood = happy;
		else if(d2 < d1 && d3 < d2 && (d2 - d3 >= d1 - d2))
			mood = sad;
		else if(d1 == d2)
		{
			if(d3 > d1)
				mood = happy;
			else
				mood = sad;
		}

		cout << mood << endl;
	}

	return 0;
}