#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int i, inum, read;
	size_t len;
	char * input = malloc(52), c, num[52], error, * ptr;
	
	while ((read = getline(&input, &len, stdin)) != -1)
	{
		error = inum = i = 0;
		//printf("inum = %i, i = %i, len = %i\n", inum, i, read);
		while(!error && i < read)
		{
			c = input[i++];
			if('0' <= c && c <= '9')	  num[inum++] = c;
			else if(c == 'O' || c == 'o') num[inum++] = '0';
			else if(c == 'l')			  num[inum++] = '1';
			else if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) error = 1;
		}

		if(inum == 0 || error)
		{
			printf("error\n");
			continue;
		}

		num[inum] = '\0';
		//printf("inum = %i, num = '%s'\n", inum, num);

		ptr = num;
		if(ptr[0] == '0')
		{
			while(inum > 1 && (*ptr) == '0') ptr++, inum--;
		}

		if(inum > 10 || (inum == 10 && strncmp(ptr, "2147483647", 10) > 0))
		{
			printf("error\n");
		}
		else
		{
			printf("%s\n", ptr);
		}
    }
	
	return 0;
}