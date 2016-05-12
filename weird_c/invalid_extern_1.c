#include <stdio.h>

int ptr[3] = {555,666,777};

void func(){
	printf("2) &ptr = %p, ", &ptr);
	printf("ptr = %p, ", ptr);
	printf("(int)ptr = %i, ", (int)ptr);
	printf("*ptr = %i\n", *ptr);
}