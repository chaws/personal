#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct 
{
	long int score;
	long int victory;
	long int goals;
	long int order;
	string name;
} team;

bool myfunction(team team1, team team2) 
{
	if(team1.score > team2.score)
		return true;
	else if(team1.score < team2.score)
		return false;

	// team1.score == team2.score
	if(team1.victory > team2.victory)
		return true;
	else if(team1.victory < team2.victory)
		return false;

	// team1.victory == team2.victory
	if(team1.goals > team2.goals)
		return true;
	else if(team1.goals < team2.goals)
		return false;

	// goals1 == goals2
	return (team1.order < team2.order);
}

int main()
{
	long int T, N, M, iN, score1, score2;
	string name1, name2;

	cin >> T;
	while(T--)
	{
		cin >> N >> M;

		map<string, team> teams;
		iN = 0;

		while(iN++ < N)
		{
			cin >> name1;
			name1[name1.size()] = '\0';
			teams[name1].order = iN;
			teams[name1].name = name1;
		}

		while(M--)
		{
			cin >> score1 >> name1 >> score2 >> name2;

			teams[name1].goals += score1;
			teams[name2].goals += score2;

			if(score1 > score2)
			{
				teams[name1].victory++;
				teams[name1].score += 3;
			}
			else if(score1 < score2)
			{
				teams[name2].victory++;
				teams[name2].score += 3;	
			}
			else
			{
				teams[name1].score++;
				teams[name2].score++;
			}
		}

		vector<team> v(N);
		for (map<string, team>::iterator it = teams.begin(); it != teams.end(); ++it)
		{
			v.push_back(teams[it->first]);
		}

		sort(v.begin(), v.end(), myfunction);

		for(int i = 0; i < v.size(); i++)
		{
			if(v[i].name.size() > 0)
				cout << v[i].name << endl;
		}
	}

	return 0;
}