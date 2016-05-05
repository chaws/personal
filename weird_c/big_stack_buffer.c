void st_overflow_001 ()
{
	double buf[1048576];/* 1MB bytes */ /*Tool should detect this line as error*/ /*ERROR:Stack overflow*/
	buf[0] = 1.0;
}

int main(void)
{
	st_overflow_001();
	return 0;
}