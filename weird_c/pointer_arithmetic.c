#include <stdio.h>
#include <stdlib.h>

int main()
{
	CHAR:
	{
		char a, *b;
		printf("CHAR\n");
		printf("a = %i, &a = %p, sizeof(a) = %lu\n", (int)a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}
	
	SHORT:
	{
		short a, *b;
		printf("SHORT\n");
		printf("a = %i, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}
	
	INT:
	{
		int a, *b;
		printf("INT\n");
		printf("a = %i, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}
	
	LONG:
	{
		long a, *b;
		printf("LONG\n");
		printf("a = %li, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}
	
	LONGLONG:
	{
		long long a, *b;
		printf("LONGLONG\n");
		printf("a = %lli, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}

	FLOAT:
	{
		float a, *b;
		printf("FLOAT\n");
		printf("a = %f, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}

	DOUBLE:
	{
		double a, *b;
		printf("DOUBLE\n");
		printf("a = %lf, &a = %p, sizeof(a) = %lu\n", a, &a, sizeof(a));
		printf("b = %p, &b = %p, sizeof(b) = %lu, b + 1 = %p\n", b, &b, sizeof(b), b + 1);
		printf("\n");
	}

	return 0;
}