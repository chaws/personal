#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num, cutoff, decpart_cutoff, intpart, decpart;
	int iNum, iCutoff, converted_int, converted_dec, converted_cutoff;
	bool roundup;

	while(cin >> num >> cutoff)
	{
		decpart = intpart = decpart_cutoff = "";

		// Get decpart of cutoff
		decpart_cutoff.push_back(cutoff[2]);
		decpart_cutoff.push_back(cutoff[3]);
		decpart_cutoff.push_back(cutoff[4]);
		decpart_cutoff.push_back(cutoff[5]);

		// intpart of num
		for(iNum = 0; iNum < num.size(); iNum++)
		{
			if(num[iNum] == '.')
			{
				break;
			}

			intpart.push_back(num[iNum]);
		}

		// decpart of num
		if(intpart.size() < num.size() - 1) // -1 is due to cases like '135.'
		{
			for(iNum++; iNum < num.size(); iNum++)
			{
				decpart.push_back(num[iNum]);
			}
		}

		if(!intpart.size())
		{
			intpart = "0";
		}

		if(!decpart.size())
		{
			decpart = "0";
		}

		// Correct pad sizes of decpart and cutoff
		if(decpart.size() < decpart_cutoff.size())
		{
			decpart.insert(decpart.size(), decpart_cutoff.size() - decpart.size(), '0');
		}
		else if(decpart_cutoff.size() < decpart.size())
		{
			decpart_cutoff.insert(decpart_cutoff.size(), decpart.size() - decpart_cutoff.size(), '0');
		}

		roundup = false;
		converted_int = stoi(intpart);
		converted_dec = stoi(decpart);
		converted_cutoff = stoi(decpart_cutoff);

		if(converted_dec > converted_cutoff)
		{
			roundup = true;
		}

		//cout << converted_int << ", " << converted_dec << ", " << converted_cutoff << endl;
		if(roundup)
		{
			converted_int++;
		}

		cout << converted_int << endl;
	}

	return 0;
}