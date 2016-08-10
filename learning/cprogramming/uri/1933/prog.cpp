#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B;
	while(cin >> A >> B)
	{
		if(A == B)
			cout << A << endl;
		else
		{
			cout << (A > B ? A : B) << endl;
		}
	}
	return 0;
}