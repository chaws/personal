#include <iostream>
#include <string>

using namespace std;

char mapa[101][101];

int main()
{
	int X, Y, ix, iy;
	char c, keep;

	while(cin >> X >> Y)
	{
		for(iy = 0; iy < Y; iy++)
		{
			for(ix = 0; ix < X; ix++)
			{
				cin >> mapa[iy][ix];
			}
		}

		c = mapa[0][0];

		if(c == '*')
		{
			cout << c << endl;
			continue;
		}

		if(c == '.' || c == '<' || c == '^' || (X == 1 & Y == 1))
		{
			cout << '!' << endl;
			continue;
		}


		keep = 1;
		iy = ix = 0;
		while(keep)
		{
			//cout << "at iy = " << iy << ", ix = " << ix << ": " << mapa[iy][ix] << endl;
			switch(mapa[iy][ix])
			{
				case '-':
					// My way of saying "It's been here before"
					c = '!', keep = 0;
					break;

				case '^':
					mapa[iy][ix] = '-';
					iy--;
					while(iy >= 0)
					{
						if(mapa[iy][ix] == '*')
						{
							c = '*', keep = 0;
							break;
						}
						else if(mapa[iy][ix] != '.')
						{
							break;
						}
						iy--;
					}

					if(iy == -1)
					{
						c = '!', keep = 0;
						break;
					}

					break;

				case '>':
					mapa[iy][ix] = '-';
					ix++;
					while(ix < X)
					{
						if(mapa[iy][ix] == '*')
						{
							c = '*', keep = 0;
							break;
						}
						else if(mapa[iy][ix] != '.')
						{
							break;
						}

						ix++;
					}

					if(ix == X)
					{
						c = '!', keep = 0;
						break;
					}

					break;

				case 'v':
					mapa[iy][ix] = '-';
					iy++;
					while(iy < Y)
					{
						if(mapa[iy][ix] == '*')
						{
							c = '*', keep = 0;
							break;
						}
						else if(mapa[iy][ix] != '.')
						{
							break;
						}

						iy++;
					}

					if(iy == Y)
					{
						c = '!', keep = 0;
						break;
					}

					break;

				case '<':
					mapa[iy][ix] = '-';
					ix--;
					while(ix >= 0)
					{
						if(mapa[iy][ix] == '*')
						{
							c = '*', keep = 0;
							break;
						}
						else if(mapa[iy][ix] != '.')
						{
							break;
						}

						ix--;
					}

					if(ix == -1)
					{
						c = '!', keep = 0;
						break;
					}

					break;
			}
		}

		cout << c << endl;
	}

	return 0;
}