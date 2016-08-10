#include <iostream>
#include <algorithm>

#define QTD_BOOKS books[ibook][0]
#define SUM_BOOKS books[ibook][1]

typedef struct _elem
{
	struct _elem * prev;
	struct _elem * next;
	int value;
} elem;

elem * newklist(int k)
{
	elem * first = (elem *) malloc(sizeof(elem));
	first->value = 0;
	first->prev = NULL;
	elem * returned = first;
	elem * temp;
	int i;
	for(i = 1; i < k; i++)
	{
		temp = (elem *) malloc(sizeof(elem));
		first->next = temp;
		temp->prev = first;
		temp->next = NULL;
		first = temp;
		first->value = 0;
	}

	return returned;
}

// Add a value, the biggest goes to the end of the list
void addkvalue(elem * list, int value)
{
	bool last = true;
	while(list->next)
	{
		if(list->value < value)
		{

		}
	}
}

using namespace std;

int main()
{
	int books[5][12], ibook; // books[][0] == qtd of books, books[][1] == sum of it
	double averages[5]; // will contain the index of the most expensive books first
	int K, i, num;

	ibook = 0;
	while(cin >> num)
	{
		QTD_BOOKS = num;
		SUM_BOOKS = 0;
		i = 2;
		while(num--)
		{
			cin >> books[ibook][i];
			SUM_BOOKS += books[ibook][i] * (i - 1); // count to get the avr
			i++;
		}

		averages[ibook] = ((float)SUM_BOOKS) / ((float)QTD_BOOKS);

		// Sort it
		sort(books[ibook] + 2, books[ibook] + 2 + QTD_BOOKS);

		for(int j = 0; j < books[ibook][0]; j++)
		{
			cout << books[ibook][j + 2] << ' ';
		}
		cout << endl;
		cout << "avr of books["<< ibook <<"] = " << averages[ibook] << " and sum = " << SUM_BOOKS << endl;

		if(++ibook == 5)
		{
			break;
		}
	}

	cin >> K;

	return 0;
}