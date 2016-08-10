#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string expr, tmp;
	int i_num, nums_i[3];

	while(cin >> expr)
	{
		//cout << expr << endl;
		string nums[3];
		i_num = 0;
		for(int i = 0; i < expr.size(); i++)
		{

			if(expr[i] == '+' || expr[i] == '=')
			{
				i_num++;
				continue;
			}

			nums[i_num].push_back(expr[i]);
		}

		for(int i = 0; i < 3; i++)
		{
			tmp = "";
			for(string::reverse_iterator rit = nums[i].rbegin(); rit != nums[i].rend(); ++rit)
			{
				tmp.push_back(*rit);
			}

			nums_i[i] = atoi(tmp.c_str());
		}

		if(nums_i[0] + nums_i[1] == nums_i[2])
			cout << "True" << endl;

		else
			cout << "False" << endl;


		//cout 
	}

	return 0;
}