#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

using namespace std;

int main()
{
	int N, tens, t[7] = {1, 10, 100, 1000, 10000, 100000, 1000000}, L, msb;
	char c;

	while(cin >> N >> c >> tens)
	{
		if(!N && !tens)
			break;

		N *= t[tens];

	    asm("bsrl %1,%0" : "=r"(msb) : "r"(N));
		L = N - (1 << msb);
	    
		cout << (1 + 2*L) << endl;
	}

	return 0;
}