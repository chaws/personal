#include <iostream>

using namespace std;

int main()
{
	int C, N, L, b, B, H;
	double h, perGlass;

	// V = (B*B + Bb + b*b)(PI * H) / 3
	// H = (3 * V)/(PI * (B*B + Bb + b*b))

	while(cin >> C)
	{
		while(C--)
		{
			cin >> N >> L;
			cin >> b >> B >> H;

			perGlass = (double)L / (double)N;
		}
	}

	return 0;
}