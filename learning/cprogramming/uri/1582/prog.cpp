#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0 || a == b)
	{
		return a;
	}
	return gcd(b, a % b);
}


int main()
{
	int A, B, C;

	while(cin >> A >> B >> C)
	{
		cout << "tripla";

		if((A*A == B*B + C*C) || (B*B == A*A + C*C) || (C*C == A*A + B*B))
		{
			cout << " pitagorica";

			if(gcd(A, gcd(B, C)) == 1)
			{
				cout << " primitiva";
			}
		}
		cout << endl;
	}

	return 0;
}