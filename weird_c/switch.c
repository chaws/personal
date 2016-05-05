#include <stdio.h>
#include <stdlib.h>

typedef union 
{
    int a;
    int b;
} somestruct;

int main()
{
    somestruct *ptr;
    ptr = (somestruct *)(-1);
    printf("ptr = %i\n", ptr->b);

    int f = 0;
    switch(f)
    {
        case 1:
        {
            printf("Case = 1\n");
            return 0;
        }
        case 2:
        {
            printf("Case = 2\n");
            return 0;
        }
        case 3:
        {
            printf("Case = 3\n");
            return 0;
        }
        default:
        {
            printf("Default\n");
        }
    }
    return 0;
}
