#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define pop(s) ((s.index) ? (s.index--) : 0)
#define push(s, v) (s.values[s.index] = v, s.index++)
#define top(s) (s.index > 0 ? s.values[s.index - 1] : -1)

typedef struct 
{
	int index;
	int values[50001];
} stack;

int main()
{
	stack pilha = {0, {0}};
	int I, iI, op, maxop, iinput,leninput, ret, found = 1, i;
	unsigned char input[100001], ops[100001], vec[30001], * ptr, trash;

	ret = scanf("%i", &I);
	ret = scanf("%c", &trash);
	iI = 0;
	while(iI++ < I)
	{
		pilha.index = 0;
		ret = scanf("%c", &trash);
		ret = scanf("%s", input);
		ret = scanf("%c", &trash);
		ret = scanf("%s", ops);

		memset(vec, 0, 30001);
		ptr = vec;
		maxop = strlen(ops);
		leninput = strlen(input);
		iinput = op = 0;

		printf("Instancia %i\n", iI);

		while(op < maxop)
		{
			//printf("op = %i\n", op);
			//printf("Processing '%c'\n", ops[op]);
			// printf("ptr = 0x%x\n", ptr);
			//printf("*ptr = %i\n", *ptr);
			switch(ops[op])
			{
				case '>': ptr = (ptr == (vec + 29999) ? vec : ptr + 1); break;
				case '<': ptr = (ptr == vec ? vec + 29999 : ptr - 1); break;
				case '+': (*ptr)++; break;
				case '-': (*ptr)--;	break;
				case '.': /*if(isalpha(*ptr))*/ printf("%c", *ptr); break;
				case ',': *ptr = (iinput < leninput ? input[iinput++] : 0);	break;
				case ']': 
					if(*ptr)
						op = top(pilha) ;//,printf("Returning to loop!!!\n");
					else
						pop(pilha), 	 // drops the head of the loop
						op = top(pilha), // recover the end of the loop
						pop(pilha) 	 // drops the end of the loop
						;//,printf("Closed loop!!!\n");
					break;

				case '[':
					//printf("Open loop!!!\n");
					// Found a head of a loop, first catch its end and store in the stack
					
					for(i = op + 1, found = 1; found && i < maxop; i++)
					{
						if(ops[i] == '[') found++;
						else if(ops[i] == ']') found--;
					}

					push(pilha, i - 1); // stores the end of the loop first (exactly ']')
					push(pilha, op); // now keeps the head of the loop (exactly '[')

					// Let's try to begin the loop
					if(*ptr)
						op = top(pilha);
					else
						pop(pilha), 	 // drops the head of the loop
						op = top(pilha), // recover the end of the loop
						pop(pilha) 	 // drops the end of the loop
						;//,printf("Closed loop!!!\n");

					break;

				case '#':
					printf("%c%c%c%c%c%c%c%c%c%c", 
						vec[0],vec[1],vec[2],vec[3],vec[4],vec[5],vec[6],vec[7],vec[8],vec[9]
					);
					break;
			}
			op++;
		}

		printf("\n\n");
	}

	return 0;
}