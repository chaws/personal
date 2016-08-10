#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define prf printf
#define scf scanf
#define G 9.80665
#define PI 3.14159

int main(void)
{
	double h, a, v, d;
	int p1, p2, n;

	while(scf("%lf", &h) != EOF)
	{
		scf("%d %d", &p1, &p2);
		scf("%d", &n);
		while(n--)
		{
			scf("%lf %lf", &a, &v);
			a = (a * PI) / 180.0;
			d = ((v * cos(a)) / G) * (v * sin(a) + sqrt(v*v * sin(a)*sin(a) + 2 * G * h));
			prf("%.5lf -> %s\n", d, (p1 <= d && d <= p2 ? "DUCK" : "NUCK"));
		}
	}

	return 0;
}
