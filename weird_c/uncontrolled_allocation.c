#include <stdlib.h>
int main(void)
{
    int i;
    long *buf;
    for (i=0;;i++)
    {
        buf = (long *)calloc(5,sizeof(long));
        if(buf != NULL)
        {
            /*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
            buf[1] = 1;
        }
    }
    return 0;
}
