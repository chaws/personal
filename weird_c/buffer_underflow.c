#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, * b, * c;
    b = &a - 2;
    c = &a + 2;
    printf("&a = \t %p \n&a - 2 = %p \n&a + 2 = %p\n", &a, b, c);
    return 0;
}
