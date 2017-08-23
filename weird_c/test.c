#include <stdio.h>
#include <stdlib.h>
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
int main()
{
    int * ptr, i, j;
    for(i = 0; i < 1000000; i++)
    {
        ptr = malloc(1000 * sizeof(int));

        for(j = 0; j < 999; j++)
            ptr[j] = i;

        free(ptr);
    }
    return 0;
}
