/*
The fibonacci final digits repeat after a certain cycle:
a) the last digit always repeat after 60th term
b) the last two digits repeat after 300th term
c) and the last three digits repeat after 1500th term, which is what we want =)


Here's the source: http://www.johndcook.com/blog/2015/08/04/last-digits-fibonacci-numbers/
If you write out a sequence of Fibonacci numbers, you can see that the last digits repeat every 60 numbers.
The 61st Fibonacci number is 2504730781961. 
The 62nd is 4052739537881. 
Since these end in 1 and 1, the 63rd Fibonacci number must end in 2, etc. and so the pattern starts over.
It’s not obvious that the cycle should have length 60, but it is fairly easy to see that there must be a cycle. 
There are only 10*10 possibilities for two consecutive digits. 
Since the Fibonacci numbers are determined by a two-term recurrence, 
 and since the last digit of a sum is determined by the sum of the last digits, 
 the sequence of last digits must repeat eventually. 
Here “eventually” means after at most 10*10 terms.
Replace “10” by any other base in the paragraph above to show that the sequence of last digits must be cyclic in any base. 
In base 16, for example, the period is 24. 
In hexadecimal notation the 25th Fibonacci number is 12511 and the 26th is 1DA31, so the 27th must end in 2, etc.
*/

#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf



int main(void)
{
	unsigned long long fib[1503] = {0}, num;
	char d[10001];
	int T, i, len;

	// Fill up first 1500 fibonacci numbers
	fib[1] = fib[2] = fib[1501] = fib[1501] = 1;
	for(i = 2; i < 1500; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1000;
	}

	while(scf("%d", &T) != EOF)
	{
		while(T--)
		{
			scf("%s%n", d, &len);
			len--;

			// Christian Bonilian's voodoo to get the modular number 
			for(num = i = 0; i < len; i++)
			{
				num *= 2;
				num += (d[i] - '0');
				num %= 1500;
			}

			prf("%03lld\n", fib[num]);
		}
	}

	return 0;
}
