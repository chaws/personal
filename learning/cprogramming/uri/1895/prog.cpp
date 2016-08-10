#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
	int N, T0, L, card, players[2], player, diff;
	queue<int> deck;

	while(cin >> N >> T0 >> L)
	{
		players[0] = players[1] = player = 0; // players-0 == Alice, players-1 == Bob
		N--;
		while(N--)
		{
			cin >> card;
			deck.push(card);
		}

		while(!deck.empty())
		{
			card = deck.front();
			deck.pop();
			diff = abs(card - T0);

			// cout << "L = " << L << ", T0 = " << T0 << ", card = " << card << endl;
			// cout << "player " << player << " just won " << diff << " points" << endl;

			if(diff <= L)
			{
				players[player] += diff;
				T0 = card;
			}

			// Change player turn
			player = !player;
		}

		cout << players[0] << ' ' << players[1] << endl;
	}

	return 0;
}