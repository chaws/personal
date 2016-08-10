#include <iostream>
#include <string>
#include <string.h>
#define magic 1000000007

using namespace std;

long int modInverse(long int a, long int m) 
{
	long int x = 1, y = 0, b = m,
    	xLast = 0, yLast = 1,
    	q, r, _m, n;
    while(a != 0) 
    {
        q = b / a, r = b % a;
        _m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = _m, y = n;
        b = a, a = r;
    }

    return (xLast + m) % m;
}

int main()
{
	string word;
	long long int res, fact[1001], i;
	int letters['Z' + 1];

	i = fact[0] = 1;
	while(i < 1001)
		fact[i] = (i * fact[i - 1]) % magic, i++;

	while(cin >> word)
	{
		memset(letters + 'A', 0, (1 + 'Z' - 'A') * sizeof(int));
		for(i = 0; i < word.size(); i++)
			letters[word[i]]++;

		for(i = 'A', res = 1; i <= 'Z'; i++)
			if(letters[i])
				res = (res * fact[letters[i]]) % magic;
 
		cout << ((fact[word.size()] * modInverse(res, magic)) % magic) << endl;
	}

	return 0;
}