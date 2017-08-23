#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

typedef struct
{
	int num1, num2, res, ops['I' + 1]; // ops['+'] = 0/1, ops['-'] = 0/1, ops['*'] = 0/1
} expr;

typedef struct 
{
	char name[51];
	int fail;
} player;

int cmpplayer(const void * p1, const void * p2)
{
	return strcmp(((player *)p1)->name, ((player *)p2)->name);
}

int main(void)
{
	expr inputs[52];
	player people[51];

	int T, iT, num1, num2, res, sel, nfail;
	char op;

	while(scf("%d", &T) != EOF)
	{
		// prf("[DEBUG] T = %d\n", T); // Debug
		iT = 0;
		while(iT < T)
		{
			scf("%d %d=%d", &inputs[iT].num1, &inputs[iT].num2, &inputs[iT].res);
			// prf("[DEBUG] inputs[%d].num1 = %d, inputs[%d].num2 = %d, inputs[%d].res = %d\n", iT, inputs[iT].num1, iT, inputs[iT].num2, iT, inputs[iT].res); // Debug

			// Try out every operator
			inputs[iT].ops['+'] = (inputs[iT].num1 + inputs[iT].num2 == inputs[iT].res);
			inputs[iT].ops['-'] = (inputs[iT].num1 - inputs[iT].num2 == inputs[iT].res);
			inputs[iT].ops['*'] = (inputs[iT].num1 * inputs[iT].num2 == inputs[iT].res);
			inputs[iT].ops['I'] = !(inputs[iT].ops['+'] || inputs[iT].ops['-'] || inputs[iT].ops['*']);
			// prf("[DEBUG] ops[+] = %d, ops[-] = %d, ops[*] = %d, ops[I] = %d\n", inputs[iT].ops['+'], inputs[iT].ops['-'], inputs[iT].ops['*'], inputs[iT].ops['I']); // Debug

			iT++;
		}

		nfail = iT = 0;
		while(iT < T)
		{
			// prf("[DEBUG] iT = %d\n", iT); // Debug
			scf("%s %d %c", people[iT].name, &sel, &op);
			// prf("[DEBUG] people[%d].name = '%s', sel = %d, op = %c\n", iT, people[iT].name, sel, op); // Debug

			people[iT].fail = !inputs[sel - 1].ops[op];
			people[iT].fail ? nfail++ : 0;

			iT++;
		}

		if(!nfail)
		{
			prf("You Shall All Pass!\n");
		}
		else if(nfail == T)
		{
			prf("None Shall Pass!\n");
		}
		else
		{
			qsort(people, T, sizeof(player), cmpplayer);

			iT = 0;
			int first = 1;
			while(iT < T)
			{
				if(people[iT].fail)
				{
					(first ? first = 0 : printf(" ")) ;

					nfail++, printf("%s", people[iT].name);
				}

				iT++;
			}

			prf("\n");
		}
	}

	return 0;
}