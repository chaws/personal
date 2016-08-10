#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

// Return the size of frase in case of word is replaced by two characters
inline int diff(string frase, string word)
{
	string s;
	stringstream ss;
	int size = frase.size(), decr = word.size() - 2;

	ss << frase;
	while(ss >> s)
		if(s.size() > 2 && s == word)
			size -= decr;
	return size;
}


typedef struct 
{
	string word;
	int reduced;
} abbr;

bool order(abbr abbr1, abbr abbr2)
{
	return abbr1.reduced < abbr2.reduced;
}

int main()
{
	std::ios::sync_with_stdio(false);

	string frase;
	bool first, first_frase;
	int how_many;

	first_frase = true;
	while(getline(cin, frase))
	{
		if(frase == ".")
			break;

		vector<abbr> abreviacoes['z' + 1];
		map<string, int> done;

		string s;
		stringstream ss, ss2;

		ss << frase;
		while(ss >> s)
		{
			if(s.size() < 3 || done[s])
				continue;

			done[s] = 1;
			abbr a;
			a.word = s;
			a.reduced = diff(frase, s);
			//cout << "word = " << a.word << ", reduced = " << a.reduced << endl;
			abreviacoes[s[0]].push_back(a);
		}

		for(int c = 'a'; c <= 'z'; c++)
			if(abreviacoes[c].size() > 0)
				sort(abreviacoes[c].begin(), abreviacoes[c].end(), order);

		ss2 << frase;
		first = true;
		while(ss2 >> s)
		{
			if(first)
				first = false;
			else
				cout << " ";

			if(abreviacoes[(int)s[0]].size() && s == abreviacoes[(int)s[0]].at(0).word)
				cout << s[0] << ".";
			else
				cout << s;
		}
		cout << endl;

		how_many = 0;
		for(int c = 'a'; c <= 'z'; c++)
			if(abreviacoes[c].size() > 0)
				how_many++;
		if(how_many)
			cout << how_many << endl;
		else
			cout << 0;

		for(int c = 'a'; c <= 'z'; c++)
			if(abreviacoes[c].size() > 0)
				cout << (char)c << ". = " << abreviacoes[c].at(0).word << endl;
	}
	
    return 0;
}