#include <stdlib.h>
#include <stdio.h>
#include <tetris.h>

int testPieceIsL()
{
    int arr[] = {'.', }
    assert('L', isL());
}

int isL()
{
    return false
}

/**
 *  Based on an input array, return the type of the part
 */
piece identifyPiece(int * arr)
{

}

void process()
{
    sortPiece()
}

int main()
{
    char input[6][6], trash, c, *pinput;

    pinput = input;

    while(scanf("%c", &c) != EOF)
    {
        if(c == '\n')
        {
            c = '.';
            pinput
        }
        *pinput = c;
        pinput++;
    }


    read();
    process();
    answer();

    return 0;
}
