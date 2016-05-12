/*
 * In this example, ptr is 'int *' in 'invalid_extern.c' and 'int[]' in 'invalid_extern_1.c'
 * that's supposed to work very fine, BUT IT DOESN'T!!!
 *
 * GCC doesn't even blink about it and when you try to execute the binary, you'll see
 * a segmentation fault. This is basically due to the fact that arrays in C are not
 * necessarily pointers!!! So the first VALUE of the definition array is used as address
 * on ptr from 'invalid_extern.c', which messes everything up and crashes.
 */
#include <stdio.h>

extern int * ptr;
extern void func();

int main(void)
{
	func();

	printf("1) &ptr = %p, ", &ptr);
	printf("ptr = %p, ", ptr);
	printf("(int)ptr = %i\n", (int)ptr);
	printf("*ptr = %i\n", *ptr);
	return 0;
}
