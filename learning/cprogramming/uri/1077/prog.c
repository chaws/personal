#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRI(c) (c == '^' ? 2 : (c == '/' || c == '*' ? 1 : (c == '(' ? -1 : 0)))
#define push iStack++, opStack[iStack].c = infix[i], opStack[iStack].pri = PRI(infix[i])

typedef struct 
{
	char c;
	char pri;
} op;

// void printStack(op * s, int i)
// {
// 	printf("Stack ");
// 	if(i == 0)
// 	{
// 		printf("is empty!\n");
// 		return;
// 	}

// 	int k;
// 	for(k = 1; k <= i; k++)
// 		printf("%c", s[k]);
// 	printf("\n");
// }

int main(void)
{
	int N, iIn, iPost, iStack, cread, i, pri;
	op opStack[301];

	while(scanf("%i", &N) != EOF)
	{
		while(N--)
		{
			iIn = iPost = iStack = 0;
			char infix[301] = {0}, postfix[301] = {0};

			scanf("%s%n", infix, &cread);
			//printf("Working on '%s'\n", infix);
			cread--;

			for(i = 0; i < cread; i++)
			{
				if(('A' <= infix[i] && infix[i] <= 'Z') || ('a' <= infix[i] && infix[i] <= 'z') || ('0' <= infix[i] && infix[i] <= '9'))
				{
					postfix[iPost++] = infix[i];
					// printf("Found1 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
				}
				else if(infix[i] == '(')
				{
					push;
					// printf("Found2 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
				}
				else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
				{
					LOOP:
					if(iStack == 0) // empty?
					{
						push;
						// printf("Found3 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
					}
					else
					{
						// Check stack's top pri
						pri = PRI(infix[i]) - opStack[iStack].pri;
						if(pri > 0)
						{
							// Just push
							push;
							// printf("Found4 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
						}
						else 
						{
							// Print top of stack
							postfix[iPost++] = opStack[iStack--].c;
							// printf("Found5 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack+1);

							// Next pos in stack
							goto LOOP;
						}
					}
				}
				else // Can only be ')'
				{
					// Go through stack until '('
					while(iStack > 0 && opStack[iStack].c != '(')
					{
						postfix[iPost++] = opStack[iStack--].c;
						// printf("Found6 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack+1);
					}
					iStack--; // Remove '('
				}
			}

			// Clean the stack
			while(iStack > 0)
			{
				postfix[iPost++] = opStack[iStack--].c;
				// printf("Found6 postfix = %s\n", postfix); printStack(opStack, iStack+1);
			}

			postfix[iPost] = '\0';
			printf("%s\n", postfix);
		}
	}

	return 0;
}