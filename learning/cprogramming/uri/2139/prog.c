/*
                            2016
      January               February               March          
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
                1  2      1  2  3  4  5  6         1  2  3  4  5  
 3  4  5  6  7  8  9   7  8  9 10 11 12 13   6  7  8  9 10 11 12  
10 11 12 13 14 15 16  14 15 16 17 18 19 20  13 14 15 16 17 18 19  
17 18 19 20 21 22 23  21 22 23 24 25 26 27  20 21 22 23 24 25 26  
24 25 26 27 28 29 30  28 29                 27 28 29 30 31        
31                                                                

       April                  May                   June          
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
                1  2   1  2  3  4  5  6  7            1  2  3  4  
 3  4  5  6  7  8  9   8  9 10 11 12 13 14   5  6  7  8  9 10 11  
10 11 12 13 14 15 16  15 16 17 18 19 20 21  12 13 14 15 16 17 18  
17 18 19 20 21 22 23  22 23 24 25 26 27 28  19 20 21 22 23 24 25  
24 25 26 27 28 29 30  29 30 31              26 27 28 29 30        
                                                                  

        July                 August              September        
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
                1  2      1  2  3  4  5  6               1  2  3  
 3  4  5  6  7  8  9   7  8  9 10 11 12 13   4  5  6  7  8  9 10  
10 11 12 13 14 15 16  14 15 16 17 18 19 20  11 12 13 14 15 16 17  
17 18 19 20 21 22 23  21 22 23 24 25 26 27  18 19 20 21 22 23 24  
24 25 26 27 28 29 30  28 29 30 31           25 26 27 28 29 30     
31                                                                

      October               November              December        
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
                   1         1  2  3  4  5               1  2  3  
 2  3  4  5  6  7  8   6  7  8  9 10 11 12   4  5  6  7  8  9 10  
 9 10 11 12 13 14 15  13 14 15 16 17 18 19  11 12 13 14 15 16 17  
16 17 18 19 20 21 22  20 21 22 23 24 25 26  18 19 20 21 22 23 24  
23 24 25 26 27 28 29  27 28 29 30           25 26 27 28 29 30 31  
30 31 
*/

#include <stdio.h>
#include <stdlib.h>

#define prf printf
#define scf scanf

int main(void)
{
	int d, m, days, months[13] = {0}, i, natal;

	months[1] = 31,
	months[2] = 29,
	months[3] = 31,
	months[4] = 30,
	months[5] = 31,
	months[6] = 30,
	months[7] = 31,
	months[8] = 31,
	months[9] = 30,
	months[10] = 31,
	months[11] = 30,
	months[12] = 31;

	natal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 25;

	while(scf("%d %d", &m, &d) != EOF)
	{
		if(m == 12)
		{
			if(d == 25)
				prf("E natal!\n");
			else if(d == 24)
				prf("E vespera de natal!\n");
			else if(d > 25)
				prf("Ja passou!\n");
			else
				prf("Faltam %d dias para o natal!\n", (25 - d));
		}
		else
		{
			days = 0;
			for(i = 1; i < m; i++)
				days += months[i];
			days += d;
			prf("Faltam %d dias para o natal!\n", (natal - days));
		}
	}
	return 0;
}
