#include <stdlib.h>
#include <stdio.h>

typedef int myArr[4];
typedef myArr * myArrPtr;
typedef myArrPtr (*myFuncPtr)();
typedef myFuncPtr (*myFuncPtrPtr)();

// Pointer to an array of 4 ints
int (*p)[4]; 

// Pointer to a function that returns a pointer to an array of 4 ints
int (*(*p2)())[4]; 

// Pointer to a function that returns a pointer to a function that returns an array of 4 int
int (*((*(*p3)())()))[4]; 

// Function that takes no argument and returns a pointer of a 4 digit array (which is also a pointer)
int (*f1())[4]
{
	return p;
}

// Function that takes no argument and returns a pointer to a function that takes no argument
// and returns an array of 4 ints
int (*(*f2())())[4]
{
	return f1;
}

int main(void)
{
	// Simple, right?
	int arr[4] = {666, 777, 888, 999}; 

	// OK
	p = &arr; p =  

	// Weird, but OK
	p2 = f1; 

	// I don't even know what to say anymore...
	p3 = f2; 

	// Note that *p3()()[1], will first do 'p + 1' then dereference, but we
	// need first dereference and then access position 1
	printf("And = %i\n", (*p3()())[1]); 

	return 0;
}