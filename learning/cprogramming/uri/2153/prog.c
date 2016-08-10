#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define prf printf
#define scf scanf

int main(void)
{
	unsigned int offset, len;
	char source[90], * regexString = "([a-z]+)\\1$";
	size_t maxMatches = 1, maxGroups = 2;

	regex_t regexCompiled;
	regmatch_t groupArray[maxGroups];

	regcomp(&regexCompiled, regexString, REG_EXTENDED);

	while(scf("%s%n\n", source, &len) != EOF)
	{
		source[len] = 0;
		//prf("Matching on %s\n", source);
		if(!regexec(&regexCompiled, source, maxGroups, groupArray, 0))
		{
			// No matches
			offset = groupArray[0].rm_so;
			//prf("len = %d, offset = %d\n", len, offset);
			source[offset + (len - offset)/2] = 0;
		}

		prf("%s\n", source);
	}

	regfree(&regexCompiled);

	return 0;
}
