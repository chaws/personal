#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string expr;
	vector<char> currentSet;
	stack< vector<char> > sets;
	stack<char> ops;
	char previousOp;

	while(cin >> expr)
	{
		cout << expr << endl;

		sets.clear();
		ops.clear();
		previousOp = 0;

		for(int i = 0; i < expr.size(); i++)
		{
			switch(expr[i])
			{
				case '{':
					cout << "Create a set" << endl;
					currentSet.clear();
					break;
				case '}':
					cout << "Close a set" << endl;
					sets.push(currentSet);
					break;
				case '(':
					cout << "Begin a separate operation" << endl;
					break;
				case ')':
					cout << "Close a separate operation" << endl;
					break;
				case '+':
					previousOp = '+';
					cout << "Sum two sets" << endl;
					ops.push(expr[i]);
					break;
				case '-':
					cout << "Extract the left from the right" << endl;
					ops.push(expr[i]);
					break;
				case '*':
					if()
					cout << "Intersection between sets" << endl;
					ops.push(expr[i]);
					break;
				default:
					cout << "Adding " << expr[i] << " to set" << endl;
					currentSet.push_back(expr[i]);
			}
		}
	}

	return 0;
}