#include <iostream>
#include <string>

using namespace std;

#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3

char matrix[26][26];
bool visited[26][26];

void swap(char * a, char * b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void printMatrix(int N)
{
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			cout << matrix[y][x];
		}
		cout << endl;
	}

	cout << '@' << endl;
}

int main()
{
	int N, in, x, y, _x, _y, max, direction;

	while(cin >> N)
	{
		if(!N)
		{
			break;
		}

		for(y = 0; y < N; y++)
		{
			for(x = 0; x < N; x++)
			{
				matrix[y][x] = 'O';
				visited[y][x] = false;

				if(x == y && x == N / 2)
				{
					matrix[x][y] = 'X';
				}
			}
		}

		max = N * N - 1;
		_x = _y = x = y = N / 2;
		in = 1;
		direction = UP;
		printMatrix(N);
		visited[y][x] = true;

		if(N > 1)
		{
			_x++;
			swap(&matrix[y][x], &matrix[_y][_x]);
			visited[_y][_x] = true;
			printMatrix(N);
			x = _x;
			y = _y;
		}

		while(in++ < max)
		{
			switch(direction)
			{
				case RIGHT:
					if(visited[y][x + 1])
						_y = y + 1;
					else
					{
						_x = x + 1;
						direction = UP;
					}
					break;

				case LEFT:
					if(visited[y][x - 1])
						_y = y - 1;
					else
					{
						_x = x - 1;
						direction = DOWN;
					}
					break;

				case UP:
					if(visited[y - 1][x])
						_x = x + 1;
					else
					{
						_y = y - 1;
						direction = LEFT;
					}
					break;

				case DOWN:
					if(visited[y + 1][x])
						_x = x - 1;
					else
					{
						_y = y + 1;
						direction = RIGHT;
					}
					break;
			}

			swap(&matrix[y][x], &matrix[_y][_x]);
			x = _x;
			y = _y;

			printMatrix(N);

			visited[y][x] = true;
		}
	}

	return 0;
}