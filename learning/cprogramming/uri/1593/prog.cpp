#include <iostream>
#include <string>
#include <queue>

#define BASE 2

using namespace std;

queue<short> * divid_by_2(queue<short> * pilha, short * rest)
{

	short last_rest, divisor, total;
	queue<short> * result = new queue<short>;
	//cout << "size of result1 = " << result->size() << endl;

	last_rest = 0;
	//cout << "size of pilha = " << pilha->size() << ", num = ";
	while(!pilha->empty())
	{
		//cout << pilha->front() << " ";
		divisor = (last_rest * 10) + pilha->front(); pilha->pop();
		last_rest = divisor % BASE;
		result->push(divisor / 2);
	}
	delete pilha;

	if(!result->empty() && result->front() == 0)
		result->pop();

	//cout << endl;

	*rest = last_rest;
	//cout << "size of result2 = " << result->size() << endl;
	return result;
}

int main()
{
	short rest;
	int T;
	unsigned long int bits;

	string num;

	cin >> T;

	while(T--)
	{
		cin >> num;
		queue<short> * pilha = new queue<short>;

		for(int i = 0; i < num.size(); i++)
		{
			pilha->push(num[i] - '0');
		}
		
		bits = 0;
		int cont = 0;
		while(!pilha->empty())
		{
			//cout << "size of pilha before = " << pilha->size() << endl;
			pilha = divid_by_2(pilha, &rest);
			if(rest)
			{
				bits++;
			}
		}

		delete pilha;

		cout << bits << endl;
	}

	return 0;
}