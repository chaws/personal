#include <iostream>
#include <iomanip>

using namespace std;

typedef struct _node
{
	int value;
	_node * next;
	_node * prev;
} node;

int main()
{
	int N, k, ik, m, im;
	bool first;
	node * circle, * ptrk, * ptrm;

	while(cin >> N >> k >> m)
	{
		if(!N && !k && !m) 
		{
			break;
		}

		circle = ptrk = ptrm = NULL;
		circle = (node *)malloc(sizeof(node));
		circle->value = 1;

		node * tmp = circle, * aux_ptrm = NULL;
		for(int i = 2; i <= N; i++)
		{
			tmp->next = (node *)malloc(sizeof(node));
			tmp->next->value = i;
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		// connect the last chain
		tmp->next = circle;
		circle->prev = tmp;

		ptrk = circle->prev;
		ptrm = circle;

		first = true;
		while(N)
		{
			if(first)
				first = false;
			else
				cout << ',';

			ik = k;
			while(ik--)
				ptrk = ptrk->next;

			im = m;
			while(im--)
				ptrm = ptrm->prev;

			// cout << "ptrk = " << ptrk->value << endl;
			// cout << "ptrm = " << ptrm->value << endl;

			if(ptrm == ptrk)
			{
				cout << setw(3) << ptrk->value;
				tmp = ptrk->prev;
				ptrk->prev->next = ptrk->next;
				ptrk->next->prev = ptrk->prev;
				free(ptrk);
				ptrk = tmp;
				N--;
			}
			else
			{
				cout << setw(3) << ptrk->value << setw(3) << ptrm->value;

				// make sure ptrm will have somebody to jump to after removed
				aux_ptrm = (ptrm->next == ptrk ? aux_ptrm = ptrk->next : NULL);

				// Remove ptrk
				tmp = ptrk->prev;
				if(tmp == ptrm)
					tmp = ptrm->prev;
				ptrk->prev->next = ptrk->next;
				ptrk->next->prev = ptrk->prev;
				free(ptrk);
				ptrk = tmp;

				// Remove ptrm
				tmp = ptrm->next;
				ptrm->prev->next = ptrm->next;
				ptrm->next->prev = ptrm->prev;
				free(ptrm);
				ptrm = tmp;

				N -= 2;
			}			
		}

		cout << endl;
	}

	return 0;
}