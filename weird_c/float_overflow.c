#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	/* code */
	double min = 9.8813129168249309e-324;

	double ret = min / 2.0;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
	printf("ret = %e\n", ret);

	return 0;
}