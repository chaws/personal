#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double A, B, C, circIn, tri, circOut, triP, r, R, gir, ros, vi;

	while(cin >> A >> B >> C)
	{
		// Perimeter
		triP = (A + B + C) / 2.0;

		// Triangle area
		tri = sqrt(triP * (triP - A) * (triP - B) * (triP - C));

		// Small circle radius
		r = tri / triP;
		circIn = M_PI * r * r;

		// Big circle
		R = (A * B * C) / sqrt((A + B + C) * (B + C - A) * (A - B + C) * (A + B - C));
		circOut = M_PI * R * R;

		ros = circIn;
		vi = tri - ros;
		gir = circOut - tri;

		printf("%.4lf %.4lf %.4lf\n", gir, vi, ros);
	}

	return 0;
}