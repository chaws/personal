#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char bitmap[52][52] = {0};

void contaminate(int y, int x, bool ignoreFirst = false)
{
	//cout << "uncoloring y = " << y << ", x = " << x << endl;
 	if(!ignoreFirst && (bitmap[y][x] == 'T' || bitmap[y][x] == 'X'))
	{
		return;
	}

	bitmap[y][x] = 'T';

	queue<pair<int, int> > list;

	//    p2 
	// p4    p5
	//    p7 
	char *p2, *p4, *p5, *p7;

	p2 = &bitmap[y - 1][x];
	p4 = &bitmap[y][x - 1];
	p5 = &bitmap[y][x + 1];
	p7 = &bitmap[y + 1][x];

	if(*p2) list.push(pair<int, int>(y - 1, x));
	if(*p4) list.push(pair<int, int>(y, x - 1));
	if(*p5) list.push(pair<int, int>(y, x + 1));
	if(*p7) list.push(pair<int, int>(y + 1, x));

	pair<int, int> temp;
	while(!list.empty())
	{
		temp = list.front();
		list.pop();

		contaminate(temp.first, temp.second);
	}
}

int main()
{
	int Y, X, x, y;

	while(cin >> Y >> X)
	{
		if(!X && !Y)
			break;

		y = 0;
		while(y++ < Y)
		{
			x = 0;
			while(x++ < X)
			{
				cin >> bitmap[y][x];
			}
		}

		y = 0;
		while(y++ < Y)
		{
			x = 0;
			while(x++ < X)
			{
				if(bitmap[y][x] == 'T')
				{
					contaminate(y, x, true);
					//cout << "Done!" << endl;
				}
			}
		}

		y = 0;
		while(y++ < Y)
		{
			x = 0;
			while(x++ < X)
			{
				cout << bitmap[y][x];
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}