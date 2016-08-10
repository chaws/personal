#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int A[5], B[5], i;

	cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
	cin >> B[0] >> B[1] >> B[2] >> B[3] >> B[4];

	for(i = 0; i < 5; i++)
	{
		if(!(A[i] ^ B[i]))
		{
			cout << "N" << endl;
			break;
		}
	}

	if(i == 5)
	{
		cout << "Y" << endl;
	}

	return 0;
}