#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	char les;
	int N, iN, matched;
	string saida;
	bool last_matched;

	while(cin >> N)
	{
		if(!N)
			break;

		stack<char> pilha;
		queue<char> entrada, requerido;

		iN = 0;
		while(iN++ < N)
			cin >> les, entrada.push(les);

		iN = 0;
		while(iN++ < N)
			cin >> les, requerido.push(les);

		saida = "";
		matched = 0;
		last_matched = true;
		while(!requerido.empty())
		{
		ENTRADA_ACABOU:
			if(requerido.empty())
				break;

			if(last_matched)
				les = requerido.front(), requerido.pop();

			// cout << "les = " << les << endl;
			while(!entrada.empty())
			{
				// cout << "saida = " << saida << endl;
				if(!pilha.empty() && les == pilha.top())
				{
					saida.append("R");
					pilha.pop();
					matched++;
					last_matched = true;
					break;
				}

				// cout << "entrada = " << entrada.front() << endl;
				if(les == entrada.front())
				{
					// cout << "found it!" << endl;
					saida.append("IR");
					entrada.pop();
					matched++;
					last_matched = true;
					if(entrada.empty()) goto ENTRADA_ACABOU;
					break;
				}

				saida.append("I");
				pilha.push(entrada.front());
				entrada.pop();
				last_matched = false;
				if(entrada.empty()) goto ENTRADA_ACABOU;
			}
			// cout << "saida = " << saida << endl;

			// second part, try to build the required part with pilha values
			if(entrada.empty() && !pilha.empty())
			{
				// cout << "les = " << les << ", pilha = " << pilha.top() << endl;
				if(les != pilha.top())
					goto IMPOSSIBLE;

				saida.append("R");
				// cout << "saida = " << saida << endl;
				pilha.pop();
				matched++;
			}
		}

		if(matched != N) goto IMPOSSIBLE;

		cout << saida << endl;
		continue;

	IMPOSSIBLE:
		cout << saida << " Impossible" << endl;
	}

	return 0;
}