#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prf printf
#define scf scanf

#define isvowal(s) ((s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'))

void p(char * c, int l)
{
	int i = 0;
	for(; i < l; i++)
		prf("'%c' ", c[i]);
	prf("\n");
}

int main(void)
{
	int T, iT, Q, op, x, len, i, isub, ix,
	buffswitch; // buffswitch works like changing switching buffers to copy S[0] to/from S[1]

	char S[2][10005];

	while(scf("%d", &T) != EOF)
	{
		iT = 1;
		while(T--)
		{
			prf("Caso #%d:\n", iT++);

			buffswitch = 0;
			scanf("%s%n", S[buffswitch], &len);
			len--;
			S[!buffswitch][len] = S[buffswitch][len] = '\0';

			// prf("Read = '%s' (%d)\n", S[buffswitch], len); // PRINTDEBUG

			scf("%d", &Q);
			// prf("Q = %d\n", Q); // PRINTDEBUG
			while(Q--)
			{
				scf("%d", &op);
				// prf("op = %d\n", op); // PRINTDEBUG
				if(op < 2)
				{
					scf("%d", &x);
					// prf("x = %d\n", x); // PRINTDEBUG
					if(op == 0) // vowals
					{
						// prf("moving %d vowals\n", x); // PRINTDEBUG
						for(i = 0; i < len; i++)
						{
							if(isvowal(S[buffswitch][i]))
							{
								// prf("found vowal '%c'\n", S[buffswitch][i]); // PRINTDEBUG
								// Find the next x-th vowal
								for(isub = i + 1, ix = 0; ix < x; isub++)
								{
									// prf("comparing to '%c'\n", S[buffswitch][isub % len]); // PRINTDEBUG
									if(isvowal(S[buffswitch][isub % len]))
									{
										ix++;
										// prf("it's vowal, find next one \n"); // PRINTDEBUG
										if(ix == x) break;
									}
								}
								S[!buffswitch][isub % len] = S[buffswitch][i];
								// p(S[!buffswitch], len); // PRINTDEBUG
								// prf("1) S[!buffswitch] = '%s', S[buffswitch] = '%s'\n", S[!buffswitch], S[buffswitch]); // PRINTDEBUG
							}
							else
							{
								// prf("found consonant '%c'\n", S[buffswitch][i]); // PRINTDEBUG
								S[!buffswitch][i] = S[buffswitch][i];
								// p(S[!buffswitch], len); // PRINTDEBUG
								// prf("2) S[!buffswitch] = '%s', S[buffswitch] = '%s'\n", S[!buffswitch], S[buffswitch]); // PRINTDEBUG
							}
						}
					}
					else
					{
						// prf("moving %d consonants\n", x); // PRINTDEBUG
						for(i = 0; i < len; i++)
						{
							if(!isvowal(S[buffswitch][i]))
							{
								// Find the next x-th consonant
								for(isub = i + 1, ix = 0; ix < x; isub++)
								{
									if(!isvowal(S[buffswitch][isub % len]))
									{
										ix++;
										if(ix == x) break;
									}
								}
								S[!buffswitch][isub % len] = S[buffswitch][i];
							}
							else
								S[!buffswitch][i] = S[buffswitch][i];
						}
					}

					buffswitch = !buffswitch; // move the switch to the buffer just copied
					// prf("= %s\n", S[buffswitch]); // PRINTDEBUG
				}
				else
				{
					
					// prf("printing\n"); // PRINTDEBUG
					prf("%s\n", S[buffswitch]);
				}
			}
		}


	}

	return 0;
}
