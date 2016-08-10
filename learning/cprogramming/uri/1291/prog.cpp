#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

#define TWO 2.0
#define FOUR 4.0
#define SIX 6.0

using namespace std;

int main()
{
	double A, B, C; // the answer areas: A - inner area, B - flowers, C - most extern area
	double 	twoRoot = sqrt(TWO), // constant of two root
			R,  // Radius
			L1, // length of hypotenuse of one subsquare
			L2, // length R - L1
			L3, // length of first base of the triangle opposite the hypotenuse of a subsquare
			L4, // length of height adjascent from the hypotenuse of a subsquare
			A1 = M_PI / SIX, // angle of the arc considering one of the subsquares of the big square
			A2, // A1 / 2
			C1, // area of the circle
			C2, // area of the arc
			C3, // area of the triangle right below the hypotenuse L1
			C4, // area of the triangle adjascent to C3
			C5, // area of the rest of what's left from arc and (C3 + C4)
			C6, // area of the rest of a quarter of a circle minus the triangle formed from top x to top y (hard to get)
			C7, // C6 * 2
			C8; // C7 - A

	while(cin >> R)
	{
		// Calculate area of the circ and the arc
		C1 = M_PI * R * R;
		C2 = (A1 * C1) / (TWO * M_PI);

		L1 = (R * twoRoot) / TWO;
		L2 = R - L1;

		A2 = A1 / TWO;
		L3 = cos(A2) * L1;
		L4 = sin(A2) * L1;

		C3 = (L3 * L4) / TWO;
		C4 = (L4 * (R - L3)) / TWO;
		C5 = C2 - ((C3 + C4) * TWO);
		A = C5 * FOUR;

		C6 = (C1 / FOUR) - (R * R) / TWO;
		C7 = C6 * TWO;
		C8 = C7 - A;
		B = C8 * TWO;

		C = (R * R) - (A + B);

		printf("%.3f %.3f %.3f\n", A, B, C);
	}

	return 0;
}