#include <stdio.h>

/**
*	Basically, every Lajota[N] is equal Lajota[N - 1] + Lajota[N - 2]. Just writing down
*	on a piece of paper can make that clear
*/
// void solution()
// {
// 	l[1] = 1;
// 	l[2] = 2;
// 	for(int i = 3; i <= 40; i++)
// 		l[i] = l[i - 1] + l[i - 2];
// }

int main()
{
	int N, l[41] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141};
	// solution();

	while(scanf("%i", &N) != EOF)
		if(!N)
			break;
		else
			printf("%i\n", l[N]);


	return 0;
}