#include <stdio.h>

int main()
{
	int N, LA, LB, SA, SB;

	while(scanf("%d %d %d %d %d", &N, &LA, &LB, &SA, &SB) != EOF)
		printf("%s\n", (LA <= N && N <= LB && SA <= N && N <= SB ? "possivel" : "impossivel"));

	return 0;
}