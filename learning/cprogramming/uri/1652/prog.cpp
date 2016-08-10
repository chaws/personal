#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> dict;

string plural(string word)
{
	if(dict.count(word))
	{
		return dict[word];
	}

	if(word.size() == 1)
	{
		word.append("s");
		return word;
	}

	char prev = word[word.size() - 2], last = word[word.size() - 1];
	if(last == 'y' && (prev != 'a' && prev != 'e' && prev != 'i' && prev != 'o' && prev != 'u'))
	{
		word.erase(word.size() - 1);
		word.append("ies");
		return word;
	}

	if(last == 'x' || last == 'o' || last == 's' || (last == 'h' && (prev == 'c' || prev == 's')))
	{
		word.append("es");
		return word;
	}

	word.append("s");
	return word;

}

int main()
{
	int L, N;
	string word1, word2;

	while(cin >> L >> N)
	{
		while(L--)
		{
			cin >> word1 >> word2;
			dict[word1] = word2;
		}

		while(N--)
		{
			cin >> word1;
			cout << plural(word1) << endl;
		}

		dict.clear();
	}



	return 0;
}