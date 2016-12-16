/*
 * Fri Dec 16 16:20:23 EST 2016
 *
 * This is a program that implements a [n unusual] way of multiplying to integers.
 * It uses pointer arithmetic inherited from concepts of the C language
 * By Paul E. Black, adapted by chaws
 */

#include <stdio.h>

// Multiply 2 [not-so-big] numbers without multiplication arithmetic operations
int mul(int a, int b)
{
  // Dynamically allocated
  struct { char f[a]; } *ar;

  return (int)&b[ar] - (int)ar;
}

int main()
{
  printf("10 * 57 = %i\n", mul(10, 57));
  printf("57 * 10 = %i\n", mul(57, 10));
  printf("100 * 100 = %i\n", mul(100, 100));
  printf("3 * 4 = %i\n", mul(3, 4));
  printf("-4 * 3 = %i\n", mul(-4, 3));
  printf("-4 * -3 = %i\n", mul(-4, -3));
  printf("0 * 0 = %i\n", mul(0, 0));
  printf("42 * 42 = %i\n", mul(42, 42));

  int a, b;
  printf("Your turn, enter two [not-so-big] integers: \n");
  scanf("%i %i", &a, &b);
  printf("%i * %i = %i\n", a, b, mul(a, b));
  return 0;
}
