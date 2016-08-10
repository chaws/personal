#include <iostream>

#define min(a, b) (a < b ? a : b)
#define swap(a, b) (a += b, b = a - b, a = a - b)


using namespace std;

int main()
{
	int La, Ca, Lb, Cb, A, B;

	while(cin >> La >> Ca >> Lb >> Cb)
	{
		A = (La > Ca ? 1 : 0);
		B = (Lb > Cb ? 1 : 0);

		if(La > Ca)
			swap(La, Ca);

		if(Lb > Cb)
			swap(Lb, Cb);

		La += Lb;
		Ca = min(Ca, Cb);
		La = min(La, Ca);
		cout << (La * La) << endl;
	}

	return 0;
}