#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	char s1[256], s2[256], cpf[12], icpf = 0, i, num1[100], inum1 = 0, num2[100], inum2 = 0;
	double sum

	fgets(s1, 256, stdin);
	fgets(s2, 256, stdin);

	for(i = 0; i < strlen(s1) - 1; i++)
	{
		if(icpf < 11)
		{
			if(isdigit(s1[i]))
				cpf[icpf++] = s1[i];
		}
		else
		{
			
		}
	}

	return 0;
}
