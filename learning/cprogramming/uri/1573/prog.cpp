#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned int A, B, C;
	unsigned long vol;

	while(cin >> A >> B >> C)
	{
		if(!A && !B && !C)
		{
			break;
		}

		if(A == B && B == C)
		{
			cout << A << endl;
			continue;
		}

		vol = A * B * C;
		cout << (int)pow(vol, 1/3.0) << endl;
	}
	return 0;
}