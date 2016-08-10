#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, num;
	vector<int> pares, impares;

	cin >> N;
	while(N--)
	{
		cin >> num;
		if(num % 2)
			impares.push_back(num);
		else
			pares.push_back(num); 
	}

	sort(impares.begin(), impares.end());
	sort(pares.begin(), pares.end());

	if(pares.size())
	{
		for(int i = 0; i < pares.size(); i++)
			cout << pares[i] << endl;
	}

	if(impares.size())
	{
		for(int i = impares.size() - 1; i > -1 ; i--)
			cout << impares[i] << endl;
	}

	return 0;
}