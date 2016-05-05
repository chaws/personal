#include <stdio.h>
#include <stdlib.h>

void func1()
{
    printf("Calling up func1\n");
}

void func2()
{
    printf("Calling up func2\n");
}

int main()
{
    void (*fptr)();
    printf("func1 is at %p\n", func1);
    printf("func2 is at %p\n", func2);
    printf("Which to execute? ");
    scanf("%p", &fptr);
    fptr();
    return 0;
}
