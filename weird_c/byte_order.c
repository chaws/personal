#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int a;
	int b;
} mytype;

int main(void)
{
	char buf[8], i;
	for(i = 0; i < 8; i++)
	{
		buf[i] = 1 << i;
		printf("buf[%i] = %x\n", i, buf[i]);
	}
	mytype * p = (mytype *)buf;
	printf("p->a = %i, *(int *)buf = %i, p->b = %i, *((int *)buf + 1) = %i\n", p->a, p->b, *(int*)buf, *((int *)buf + 1));
	return 0;
}