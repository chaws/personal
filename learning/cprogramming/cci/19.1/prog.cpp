#include <iostream>

using namespace std;

inline void swap(int * A, int * B)
{
	*A = *A + *B; // A1 = A0 + B0
	*B = *A - *B; // B1 = A1 - B0 == (A0 + B0) - B0 == A0
	*A = *A - *B; // A2 = A1 - B1 == (A0 + B0) - A0 == B0
}

int main()
{
	int A, B;

	while(cin >> A >> B)
	{
		swap(&A, &B);
		cout << A << ' ' << B << endl;
	}

	return 0;
}