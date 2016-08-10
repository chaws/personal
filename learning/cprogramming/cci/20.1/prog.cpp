/*
Write a function that adds two numbers. You should not use + or any arithmetic operators.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B, _A, _B, C, carry, sum, i, maxbits, bothSet;
	unsigned int powerTwo;

	maxbits = sizeof(int) * 8;

	while(cin >> A >> B)
	{
		powerTwo = 1;
		carry = 0;
		C = 0;
		i = 0;

		while(i++ < maxbits)
		{
			_A = (A & powerTwo);
			_B = (B & powerTwo);

			sum = _A | _B;
			bothSet = _A & _B;

			if(sum)
			{
				if(bothSet)
				{
					if(carry)
					{
						C |= powerTwo;
						// Set this bit at pass on carry
					}
					else
					{
						carry = 1;
						// C will be zero at powerTwo-th bit
					}
				}
				else
				{
					if(!carry)
					{
						// sum is added
						C |= powerTwo;
					}
					// else carry will be added with the sum, resulting in 0 and passing carry = 1, so we don't touch it
					// C will be zero at powerTwo-th bit
				}
			}
			else // sum == 0
			{
				if(carry)
				{
					carry = 0;
					C |= powerTwo; 
				}
			}

			powerTwo <<= 1;
		}

		cout << C << endl;
	}

	return 0;
}