#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

bool division_by_zero;
bool invalid;

bool is_valid(char num)
{
	return ('0' <= num && num <= '9');
}

long long int calculate(vector<char> &expr)
{
	int num1, result = 0;
	char op, num1_c, num2_c;

	num2_c = expr.back(); expr.pop_back();

	if(!is_valid(num2_c))
	{
		//printf("'%c' is invalid1\n", num2_c);
		invalid = true;
		return 0;
	}

	result = num2_c - '0';

	while(expr.size())
	{
		num1_c = expr.back(); expr.pop_back();

		if(!is_valid(num1_c))
		{
			//printf("'%c' is invalid2\n", num1_c);
			invalid = true;
			return 0;
		}

		num1 = num1_c - '0';

		op = expr.back(); expr.pop_back();

		switch(op)
		{
			case '+':
				result += num1;
				break;

			case '-':
				result -= num1;
				break;

			case '*':
				result *= num1;
				break;

			case '/':
				if(num1 == 0)
				{
					division_by_zero = true;
					num1 = 1;
				}

				result /= num1;
				break;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int result;
	vector<char> expr;
	char tmp;

	while(scanf("%c", &tmp) != EOF)
	{
		if(tmp == ' ')
		{
			continue;
		}

		if(tmp == '\n')
		{
			// for(int i = 0; i < expr.size(); i++)
			// {
			// 	printf("%c ", expr[i]);
			// }
			// printf("\n");
			// expr.clear();
			// continue;
			if(expr.size() == 1)
			{
				printf("The answer is %i.\n", (expr[0] - '0'));
				expr.clear();
				continue;
			}

			division_by_zero = invalid = false;
			result = calculate(expr);

			if(invalid)
			{
				printf("Invalid expression.\n");
				expr.clear();
				continue;	
			}

			if(division_by_zero)
			{
				printf("Division by zero.\n");
				expr.clear();
				continue;
			}

			printf("The answer is %i.\n", result);
			expr.clear();
			continue;
		}

		expr.push_back(tmp);
	}

	if(expr.size() == 1)
	{
		printf("The answer is %i.\n", expr[0] - '0');
		return 0;
	}

	division_by_zero = invalid = false;
	result = calculate(expr);

	if(invalid)
	{
		printf("Invalid expression.\n");
		return 0;	
	}

	if(division_by_zero)
	{
		printf("Division by zero.\n");
		return 0;
	}

	printf("The answer is %i.\n", result);


	return 0;
}