#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	double L;
	while(scanf("%lf", &L))
	{
		if(!L)
		{
			break;
		}

		printf("%.6lf\n", ((L - 3.0)/L));
	}

	return 0;
}