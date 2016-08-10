#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int n, prev, val, upDown, diff;

	scf("%d", &n);
	if(n < 2)
	{
		prf("1\n");
		return 0;
	}

	scf("%d", &prev); n--;
	scf("%d", &val); n--;
	upDown = val - prev;// > 0 going up, <0 going down, =0, error
	if(!upDown)
	{
		prf("0\n");
		return 0;
	}

	prev = val;
	while(n--)
	{
		scf("%d", &val);
		diff = val - prev;
		
		if(!diff || (upDown < 0 && diff < 0) || (upDown > 0 && diff > 0))
		{
			prf("0\n");
			return 0;
		}
		prev = val, upDown = diff;
	}

	prf("1\n");
	return 0;
}
