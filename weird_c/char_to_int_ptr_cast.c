#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = 3, b = 2, c = 1, d[1], e = 0, f = 1, g = 2, h = 3;
    int * p = (int *)d;
    *p = 0xFFFFFF;
    printf("a = %i, b = %i, c = %i, *d = %i, *p = %i\n", a, b, c, *d, *p);
    return 0;
}
