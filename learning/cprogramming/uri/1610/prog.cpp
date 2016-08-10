#include <iostream>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

map<int, int> hits;

// Return true if there's a loop, false otherwise
inline bool visit(int num, vector<int> * graph)
{
	//cout << "visiting " << num << endl;
	if(graph[num].size() == 0)
	{
		return false;
	}

	// Check if it's been here
	if(hits[num])
	{
		hits.clear();
		return true;
	}
	hits[num] = 1;

	int graphlen = graph[num].size();
	for(int j = 0; j < graphlen; j++)
	{	
		if(visit(graph[num][j], graph))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int T, N, M, a, b;

	cin >> T;
	while(T--)
	{
		vector<int> graph[10001];

		cin >> N >> M;
		while(M--)
		{
			cin >> a >> b;
			//cout << "reading a = " << a << ", b = " << b << endl;
			graph[a].push_back(b);
		}

		for(int i = 1; i <= N; i++)
		{
			hits.clear();
			if(visit(i, graph))
			{
				cout << "SIM" << endl;
				goto CLEAR;
			}
		}

		cout << "NAO" << endl;

		CLEAR:
		for(int i = 1; i <= N; i++)
			graph[i].clear();
	}

	return 0;
}