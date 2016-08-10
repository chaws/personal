#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	double N;
	cout.precision(4);
	while(cin >> N)
	{
		
		cout << std::scientific << std::uppercase << std::showpos << N << endl;
	}
	return 0;
}