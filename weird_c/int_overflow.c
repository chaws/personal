#include <stdio.h>
#include <stdlib.h>

typedef struct {
	signed int max : 5;
	signed int ret : 5;
} data_overflow_009_s_001;

void data_overflow_009 ()
{
	data_overflow_009_s_001 s;
	s.max = 0x1f;
	s.ret = s.max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
	printf("s.ret = %i (0x%x)\n", s.ret, s.ret);
}

int main(int argc, char const *argv[])
{
	data_overflow_009();

	int max = 0x40000000;
	int ret;
	ret = max * 2;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
    printf("ret = %i\n", ret);

	return 0;
}