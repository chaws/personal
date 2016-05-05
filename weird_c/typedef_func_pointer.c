#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*pointertoarr)[4];
int (*func_pointer_012_func_001())[4]
{
	int (*p)[4];
	int arr[4][4] = {{1,2,3,4},
			         {11,22,33,44},
			         {33,44,55,66},
			         {55,66,77,88}};
	int i,j;
	p= (int (*)[]) malloc (sizeof arr);
	if(p!=NULL)
	{
	   memcpy(p, arr, sizeof(arr));
	   for (i = 0;i< 4; i++)
	   {
		   for ( j=0 ;j<4; j++)
		   {
			   *(p[i]+j) += *(p[i]+j);
		   }
	   }
	}
	return p;
}

int (*foo(int a))(int) 
{
	int (*fptr)(int);
	return fptr;
}

int main(int argc, char const *argv[])
{
	int (*ptr_main)(int, char const **);
	//int (*ptr_func_that_returns_array)[3](int, char const **) ;
	//printf("sizeof(ptr_func_that_returns_array) = %lu\n", sizeof(ptr_func_that_returns_array));
	int (*p)[4]; int arr[4][4];
	p = &arr[0][0];
	printf("sizeof(p) = %lu, sizeof(arr) = %lu, \n", sizeof(p), sizeof(arr));
	printf("sizeof(pointertoarr) = %lu\n", sizeof(pointertoarr));
	printf("sizeof(ptr_main) = %lu\n", sizeof(ptr_main));
	return 0;
}