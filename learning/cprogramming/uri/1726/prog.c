// This was based on problem 1077: infix to postfix form

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRI(c) (c == '*' ? 1 : (c == '(' ? -1 : 0))
#define push iStack++, opStack[iStack].c = infix[i], opStack[iStack].pri = PRI(infix[i])

typedef struct 
{
	char c;
	char pri;
} op;

void print(char * c, int s)
{
	int i = 0;
	for(; i < s; i++) printf("%c", c[i]);
	printf("\n");
}

// Add two sets
int sum(char * out, char * el1, size_t sel1, char * el2, size_t sel2)
{
	// If el1 is zero, just copy el2
	if(sel1 == 0)
	{
		strncpy(out, el2, sel2);
		return sel2;
	}
	// Otherwise, if el2 is zero, just copy el1
	else if(sel2 == 0)
	{	
		strncpy(out, el1, sel1);
		return sel1;
	}

	int written = 0;

	if(sel1 > sel2)
	{
		// el1 is guiding
		while(sel1--)
		{
			// Put the smallest char first
			if(*el1 < *el2)
				*out = *el1, el1++;
			else if(*el1 > *el2)
				*out = *el2, sel1++, sel2--;
			else
				*out = *el1, el1++, el2++, sel2--;

			printf("sum1) writting '%c'\n", *out);
			written++;
			out++;

			// If el2 is done, just copy the rest of el1
			if(!sel2)
			{
				strncpy(out, el1, sel1);
				printf("sum1) finish writting :"); print(out, sel1);
				return written + sel1;
			}
		}

		// If el2's still kicking, just copy the rest of el2
		if(sel2)
		{
			strncpy(out, el2, sel2);
			printf("sum1) finish writting 2 :"); print(out, sel2);
			return written + sel2;
		}
	}
	else
	{
		// el2 is guiding
		while(sel2--)
		{
			// Put the smallest char first
			if(*el2 < *el1)
				*out = *el2, el2++;
			else if(*el2 > *el1)
				*out = *el1, el1++, sel1--, sel2++;
			else
				*out = *el2, el2++, el1++, sel1--;
			printf("sum2) writting '%c'\n", *out);
			written++;
			out++;

			// If el1 is done, just copy the rest of el2
			if(!sel1)
			{
				strncpy(out, el2, sel2);
				printf("sum2) finish writting :"); print(out, sel2);
				return written + sel2;
			}
		}

		// If el2's still kicking, just copy the rest of el2
		if(sel1)
		{
			strncpy(out, el1, sel1);
			printf("sum1) finish writting 2 :"); print(out, sel1);
			return written + sel1;
		}
	}

	return written;
}

// Remove all el2 that is present in el1
int sub(char * out, char * el1, size_t sel1, char * el2, size_t sel2)
{
	// If el1 is zero, return empty set
	if(sel1 == 0)
	{
		*out = 0;
		return 0;
	}
	// Otherwise, if el2 is zero, just copy el1
	else if(sel2 == 0)
	{	
		strncpy(out, el1, sel1);
		return sel1;
	}

	int written = 0, iel1, iel2;

	for(iel2 = 0; iel2 < sel2; iel2++)
	{
		printf("sub = %c\n", *el2);
		while(sel1 && *el1 < *el2) 
		{
			*out = *el1;
			printf("sub2) writting '%c'\n", *out);
			out++;
			written++;
			el1++;
			sel1--;
		}
		el2++;
		el1++;
		sel1--;
	}

	return written;
}

// Intersection between el1 and el2
int mul(char * out, char * el1, size_t sel1, char * el2, size_t sel2)
{
	// if either el1 or el2 are empty, intersection should also be empty
	if(sel1 == 0 || sel2 == 0)
	{
		*out = 0;
		return 0;
	}
	
	int written = 0, iel1, iel2;

	for(iel2 = 0; iel2 < sel2; iel2++)
	{
		printf("mul = %c\n", *el2);
		while(sel1 && *el1 < *el2);

		if(*el1 == *el2)
		{
			*out = *el2;
			printf("mul1) writting '%c'\n", *out);
			out++;
			written++;
			el1++, sel1--;
			el2++;
		}
	}

	return written;
}

// Encapsulate an element
typedef struct 
{
	char * el;
	int sel;
} el;

void process(char * postfix)
{
	char *el, result[300], tempbuf[300];
	int sel, ielstack;
	el[300] elstack;
	ielstack = 0;

	// Process postfix string
	while(*postfix != '\0')
	{
		// Add el to elstack
		if(*postfix == '{')
		{
			// Get el
			postfix++, elstack[ielstack].el = postfix; // { + 1
			sel = 0;
			while(*postfix != '}') sel++, postfix++;
			elstack[ielstack].sel = sel;
			ielstack++;
			printf("p) sel = %d, el = ", sel); print(elstack[ielstack].el, sel);
		}
		// It's an operator, evaluate it
		else
		{
			switch(*postfix)
			{
				case '+': sel = sum(tempbuf, elstack); break;
				case '-': sel = sub(tempbuf, elstack); break;
				case '*': sel = mul(tempbuf, elstack); break;
			}

			strncpy(result, tempbuf, sel1);
			ielstack -= 2;
			elstack[ielstack].el = result;
			elstack[ielstack].sel = sel;
		}

		postfix++;
	}

	el1[sel1] = '\0';
	printf("{%s}\n", el1);
}

int chrcmp(const void * c1, const void * c2)
{
	return *(char *)c1 - *(char *)c2;
}

int main(void)
{
	int iPost, iStack, cread, i, pri, start_sort, end_sort;
	char infix[301] = {0}, postfix[301] = {0};
	op opStack[301];

	while(scanf("%s%n", infix, &cread) != EOF)
	{
		iPost = iStack = 0;
		printf("Read = %s: ", infix);
		cread--;

		for(i = 0; i < cread; i++)
		{
			if(infix[i] == '{')
			{
				// Save {...}
				start_sort = iPost + 1;
				while(infix[i] != '}')
					postfix[iPost++] = infix[i], i++;
				end_sort = iPost - 1;
				postfix[iPost++] = infix[i]; // }

				// make sure the letters are sorted
				//printf("end_sort= %d, start_sort = %d\n", end_sort, start_sort);	
				if(end_sort - start_sort > 0)
				{
					//printf("sorting '%c' to '%c'\n", *(postfix + start_sort), *(postfix + end_sort + 1));
					qsort(postfix + start_sort, end_sort - start_sort + 1, sizeof(char), chrcmp);
				}

				// printf("Found1 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
			}
			else if(infix[i] == '(')
			{
				push;
				// printf("Found2 %c, postfix = %s\n", infix[i], postfix); printStack(opStack, iStack);
			}
			else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*')
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
		printf("before %s\n", postfix);
		process(postfix);
	}

	return 0;
}