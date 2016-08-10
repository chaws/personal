#include <iostream>
#include <string>

using namespace std;

bool is_triangle(int a, int b, int c)
{
	return (a + b > c) && (a + c > b) && (b + c > a);
}

int main()
{
	int v1, v2, v3, v4;

	while(cin >> v1 >> v2 >> v3 >> v4)
	{
		if(is_triangle(v1, v2, v3) || 
		   is_triangle(v1, v2, v4) ||
		   is_triangle(v1, v3, v4) ||
		   is_triangle(v2, v3, v4)
		)
			cout << 'S' << endl;
		else
			cout << 'N' << endl;
	}

	return 0;
}