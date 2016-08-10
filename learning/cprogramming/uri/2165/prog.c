#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	char t[510];
	int len;
	len = read(0, t, 501);
	prf("%s\n", (len <= 140 ? "TWEET" : "MUTE"));
	return 0;
}
