#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int matrix[1002][1002] = {0}, X, Y, iX, iY;

int check(int x, int y)
{
	
	return (
		// check up
		(matrix[x-1][y-1] & matrix[x][y-1] & matrix[x+1][y-1] &
		// left - right
		matrix[x-1][y]               & matrix[x+1][y]   &
		// bottomatrix
		matrix[x-1][y+1] & matrix[x][y+1] & matrix[x+1][y+1]) == 7
	);
}

int main(void)
{
	while(scf("%i %i", &X, &Y) != EOF)
	{
		for(iX = 1; iX <= X; iX++)
			for(iY = 1; iY <= Y; iY++)
				scf("%i", &matrix[iX][iY]);

		for(iX = 1; iX < X; iX++)
		{
			for(iY = 1; iY < Y; iY++)
			{
				if(matrix[iX][iY] == 42 && check(iX, iY))
				{
					prf("%i %i\n", iX, iY);
					goto KEEP;
				}
			}
		}

		printf("0 0\n");
		KEEP:
		;
	}

	return 0;
}
