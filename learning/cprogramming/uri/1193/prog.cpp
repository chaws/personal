#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdlib.h>

using namespace std;

void hex2bin(string hexstr)
{
    long int n;
    long int i;

    if(hexstr[0] == '-')
    {
    	cout << " bin" << endl;
    	return;
    }

    stringstream ss;
    ss << (long int)stol(hexstr, nullptr, 16);
    ss >> n;

    if(n <= 0)
    {
    	cout << " bin" << endl;
    	return;
    }

    ss << hex << hexstr;
    ss >> n;

    bitset<64> b(n);
    
    string trimmed = b.to_string();

    for(i = 0; i < trimmed.size(); i++)
    {
    	if(trimmed[i] != '0')
    	{
    		break;
    	}
    }

	trimmed.erase(0, i);

    cout << trimmed  << " bin" << endl;
}

void hex2dec(string hexstr)
{
	long int mul = 1;
	if(hexstr[0] == '-')
	{
		mul = -1;
		hexstr.erase(0, 1);
	}
	cout << dec << (mul * (long int)stol(hexstr, nullptr, 16)) << " dec" << endl;
}

void bin2hex(string bin)
{  
    cout << hex << (long int)stol(bin, nullptr, 2) << " hex" << endl;
}

void bin2dec(string bin)
{
	// unsigned int val = 0;
	// for(int i = bin.size() - 1; i-- >= 0; i++)
	// {
	// 	val += 1
	// }
	cout << dec << stoll(bin, nullptr, 2) << " dec" << endl;
}

void dec2hex(string dec)
{
	cout << hex << (long int)stol(dec) << " hex" << endl;
}

void dec2bin(string dec)
{
	long int n = (long int)stol(dec);
	if(n <= 0)
	{
		cout << " bin" << endl;
		return;
	}

	string r;

	if(n == 0)
	{
		r = "0";
	}

    while(n != 0)
    {
    	r = (n % 2 ? "1" : "0") + r; 
    	n /= 2;
    }

    string trimmed = r;
    long int i;
    for(i = 0; i < trimmed.size(); i++)
    {
    	if(trimmed[i] != '0')
    	{
    		break;
    	}
    }

	trimmed.erase(0, i);

    cout << trimmed  << " bin" << endl;
}

int main()
{
	int T, iT;
	string num, base;

	cin >> T;

	iT = 0;
	while(iT++ < T)
	{
		cin >> num >> base;

		cout << "Case " << iT << ":" << endl;
		if(base == "dec")
		{
			dec2hex(num);
			dec2bin(num);
		}
		else if(base =="hex")
		{
			hex2dec(num);
			hex2bin(num);	
		}
		else
		{
			bin2dec(num);
			bin2hex(num);	
		}

		cout << endl;
	}

	return 0;
}