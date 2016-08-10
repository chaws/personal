#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int N, l, c, m[4][4], tile, prevR, prevL, prevU, prevD;
	bool right, left, up, down, first, finished;

	cin >> N;

	while(N--)
	{
		finished = right = left = up = down = false;

		for(l = 0; l < 4; l++)
		{
			for(c = 0; c < 4; c++)
			{
				cin >> m[l][c];
				if(m[l][c] == 2048)
				{
					finished = true;
				}
			}
		}

		if(finished)
		{
			cout << "NONE" << endl;
			continue;
		}

		for(l = 0; l < 4; l++)
		{
			prevR = m[l][0];
			prevL = m[l][3];

			prevU = m[3][l];
			prevD = m[0][l];

			for(c = 1; c < 4; c++)
			{
				if(!right)
				{
					if(prevR && (prevR == m[l][c] || !m[l][c]))
					{
						right = true;
					}

					prevR = m[l][c];
				}

				if(!left)
				{
					if(prevL && (prevL == m[l][3 - c] || !m[l][3 - c]))
					{
						left = true;
					}

					prevL = m[l][3 - c];
				}

				if(!up)
				{
					if(prevU && (prevU == m[3 - c][l] || !m[3 - c][l]))
					{
						up = true;
					}

					prevU = m[3 - c][l];	
				}

				if(!down)
				{
					//cout << "prevD = " << prevD << endl;
					if(prevD && (prevD == m[c][l] || !m[c][l]))
					{
						down = true;
					}

					prevD = m[c][l];
				}
			}
		}

		first = false;

		if(down)
		{
			cout << "DOWN";
			first = true;
		}

		if(left)
		{
			if(first)
			{
				cout << " ";
			}
			cout << "LEFT";
			first = true;
		}

		if(right)
		{
			if(first)
			{
				cout << " ";
			}
			cout << "RIGHT";
			first = true;
		}

		if(up)
		{
			if(first)
			{
				cout << " ";
			}
			cout << "UP";
		}

		if(!first)
		{
			cout << "NONE";
		}

		cout << endl;
	}

	return 0;
}