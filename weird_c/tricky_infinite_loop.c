/*
 * Becase 'c' is a 8 bits long, with 1 bit for signal
 * 'c' ranges until 127 and then goes back to its minimum value, -128
 * this cause 'c' never getting to 'd', which is unsigned and will be evaluated
 * to 255 ALWAYS
 */
#include <stdio.h>

int main(void)
{
    char c;
    unsigned char d = 0xFF;
    for(c = 0; c < d; c++)
    {
        printf("Again! c = %i < d = %i ??? \n", c, d);
    }

    return 0;
}
