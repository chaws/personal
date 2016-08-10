#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * a = malloc(sizeof(int));
    float * b = malloc(sizeof(float));
    a = (int *)b;
    *a = 1.5;
    printf("a = %i, hex = 0x%x\n", *a, *a);
    return 0;
}
