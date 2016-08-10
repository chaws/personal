#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct 
{
	char name[10];
	unsigned int points;
} person;

inline unsigned int force(string &name)
{
	unsigned int sum = 0;
	for(int i = 0; i < name.size(); i++)
		sum += name[i];
	return sum;
}

int main()
{
	int N, Ni, search, left, right;
	person * people = (person *)malloc(10001 * sizeof(person)), * p;
	if(!people)
	{
		cout << "Nao alocou!!!" << endl;
		return -1;
	}
	people->points = 10;
	people->name = strdup("lala");
return 0;
	unsigned long int A, B;
	while(cin >> N)
	{
		if(!N)
			break;

		Ni = 0;
		while(Ni++ < N)
		{
			cin >> people[Ni].name;
			people[Ni].points = force(people[Ni].name);
		}

		if(N == 1)
		{
			cout << "Impossibilidade de empate." << endl;
			continue;
		}

		map<int, int> hits;

		left = 1;
		right = N;
		search = (right - left) / 2;
		hits[search] = 1;
		// cout << "search is " << people[search].name << endl;
		for(A = 0, Ni = 1; Ni <= search; Ni++)
		{
			// cout << (search - Ni + 1) << " * " << people[Ni].points << " => " << people[Ni].name << endl;
			A += (search - Ni + 1) * people[Ni].points;
		}

		for(Ni = search + 1, B = 0; Ni <= N; Ni++)
		{
			// cout << (Ni - search) << " * " << people[Ni].points << " => " << people[Ni].name << endl;
			B += (Ni - search) * people[Ni].points;
		}

		if(A == B)
		{
			cout << people[Ni].name << endl;
			continue;
		}

		// cout << "A = " << A << ", B = " << B << endl;

		while(left < right)
		{
			// cout << "left = " << people[left].name << ", right = " << people[right].name << endl;
			if(A < B)
			{
				// Go to the middle right
				left = search;
				search = left + (right - left) / 2;
			}
			else
			{
				// Go to the middle left
				right = search;
				search = left + (right - left) / 2;
			}

			if(hits[search] == 1)
			{
				cout << "Impossibilidade de empate." << endl;
				break;
			}
			// cout << "search is " << people[search].name << endl;
			hits[search] = 1;
			for(A = 0, Ni = 1; Ni <= search; Ni++)
			{
				// cout << (search - Ni + 1) << " * " << people[Ni].points << " => " << people[Ni].name << endl;
				A += (search - Ni + 1) * people[Ni].points;
			}

			for(Ni = search + 1, B = 0; Ni <= N; Ni++)
			{
				// cout << (Ni - search) << " * " << people[Ni].points << " => " << people[Ni].name << endl;
				B += (Ni - search) * people[Ni].points;
			}

			// cout << "A = " << A << ", B = " << B << endl;
			if(A == B)
			{
				cout << people[search].name << endl;
				break;
			}
		}
	}
	return 0;
}