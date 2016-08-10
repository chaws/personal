#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int bitmap[1002][1002] = {0};

void uncolor(int y, int x)
{
	cout << "uncoloring y = " << y << ", x = " << x << endl;
 	if(bitmap[y][x] == 0)
	{
		return;
	}

	bitmap[y][x] = 0;

	queue<pair<int, int> > list;

	// p1 p2 p3
	// p4    p5
	// p6 p7 p8
	int *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

	p1 = &bitmap[y - 1][x - 1];
	p2 = &bitmap[y - 1][x];
	p3 = &bitmap[y - 1][x + 1];

	p4 = &bitmap[y][x - 1];
	p5 = &bitmap[y][x + 1];

	p6 = &bitmap[y + 1][x - 1];
	p7 = &bitmap[y + 1][x];
	p8 = &bitmap[y + 1][x + 1];

	if(*p1) list.push(pair<int, int>(y - 1, x - 1));
	if(*p2) list.push(pair<int, int>(y - 1, x));
	if(*p3) list.push(pair<int, int>(y - 1, x + 1));
	if(*p4) list.push(pair<int, int>(y, x - 1));
	if(*p5) list.push(pair<int, int>(y, x + 1));
	if(*p6) list.push(pair<int, int>(y + 1, x - 1));
	if(*p7) list.push(pair<int, int>(y + 1, x));
	if(*p8) list.push(pair<int, int>(y + 1, x + 1));

	pair<int, int> temp;
	while(!list.empty())
	{
		temp = list.front();
		list.pop();

		uncolor(temp.first, temp.second);
	}
}

int main()
{
	int Y, X, x, y, numObjs;

	while(cin >> Y >> X)
	{
		y = 0;
		while(y++ < Y)
		{
			x = 0;
			while(x++ < X)
			{
				cin >> bitmap[y][x];
			}
		}
	}

	numObjs = 0;

	y = 0;
	while(y++ < Y)
	{
		x = 0;
		while(x++ < X)
		{
			if(bitmap[y][x])
			{
				numObjs++;
				uncolor(y, x);
				cout << "Done!" << endl;
			}
		}
	}

	cout << numObjs << endl;

	return 0;
}