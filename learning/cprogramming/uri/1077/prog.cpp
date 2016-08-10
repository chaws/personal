#include <iostream>
#include <string>

using namespace std;

typedef struct _node
{
	char op;
	_node * left;
	_node * right;	
} node;

node * newTree(char op, node * left = NULL, node * right = NULL)
{
	node * n = (node *)malloc(sizeof(node));
	n->op = op;
	n->left = left;
	n->right = right;
	return n;
}

bool isOp(char c)
{
	return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
}

bool isNum(char c)
{
	return !isOp(c) && c != '(' && c != ')';
}

node * processExp(string substr)
{
	char op;
	node * left, * right;

	cout << "Processing " << substr << endl;

	if(!substr.size());
		return NULL;

	if(substr[0] == '(')
	{
		int opened = 1, i;
		for(i = 1; opened && i < substr.size(); i++)
		{
			if(substr[i] == '(')
				opened++;
			else if(substr[i] == ')')
				opened--;
		}

		node * temp = processExp(substr.substr(1, i));
	}

	
	if(isNum(substr[0]))
		left = newTree(substr[0]);

	if(isOp(substr[1]))
		op = isOp(substr[1]);
	
	// Tricky part
	if(isNum(substr[2]))
	{
		cout << "perfect" << endl;
		node * right = newTree(substr[2]);
		return newTree(substr[1], left, right);
	}

	return NULL;
}

void LRV(node * tree)
{
	if(!tree)
		return;

	//cout << "Going thru" << endl;

	if(tree->left)
		LRV(tree->left);

	if(tree->right)
		LRV(tree->right);

	cout << tree->op;
}

int main()
{
	string infix;
	int N;
	node * tree;

	while(cin >> N)
	{
		while(N--)
		{
			cin >> infix;
			tree = processExp(infix);
			LRV(tree);
		}
	}

	return 0;
}