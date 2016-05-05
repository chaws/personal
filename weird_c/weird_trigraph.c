#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 1, i;
  for(i = 0; i < 100; ++i);
    // What will the next line do? Increment?????/
   	x = x + 1;
  printf("%i\n", x);
}