#include <stdio.h>
#include <stdlib.h>

void fun(double val, int val2) {
    int x2 = val; // if val==7.9, x2 becomes 7 (bad)
    char c2 = val2; // if val2==1025, c2 becomes 1 (bad)
    int x3 {val}; // error: possible truncation (good)
    char c3 {val2}; // error: possible narrowing (good)
    char c4 {24}; // OK: 24 can be represented exactly as a char (good)
    char c5 {264}; // error (assuming 8-bit chars): 264 cannot be represented as a char (good)
    int x4 {2.0}; // error: no double to int value conversion (good)
}

int main(void)
{
    char dict[][15] = {{"aword"}, {"bword"}, {"cword"}};
    char dict2[] = "somestring";
    int i = {0};
    int j = 3.2;
    int k = {3.2};


    printf("j = %i\n", j);
    printf("k = %i\n", k);

    for(i = 0; i < 3; i++)
    {
        printf("dict[%i] = \"%s\"\n", i, dict[i]);
    }

    return 0;
}
