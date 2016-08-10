#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	string input;
	unsigned long int h, m, s, click, click2;
	long double dst, newvel, vel;
	char crap;

	click = h = m = s = 0;
	vel = dst = 0.0;
	while(getline(cin, input))
	{
		stringstream ss;
		ss << input;
		newvel = -1.0;
		ss >> h >> crap >> m >> crap >> s >> newvel;

		click2 = h * 3600 + m * 60 + s;
		dst += ((click2 - click) * (vel / 3.6)) / 1000.0;
		click = click2;

		if(newvel != -1.0)
			vel = newvel;
		else
		{
			if(h < 10) cout << '0';	cout << h << ':';
			if(m < 10) cout << '0';	cout << m << ':';
			if(s < 10) cout << '0';	cout << s;
			cout << ' ' << setprecision(2) << fixed << dst << " km" << endl;
		}
	}

	return 0;
}