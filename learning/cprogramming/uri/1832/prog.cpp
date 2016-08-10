#include <iostream>
#include <string>

using namespace std;

int main()
{
	char ebcdic[256] = {0};

	ebcdic[64] = ' ';

	ebcdic[240] = '0';ebcdic[241] = '1';ebcdic[242] = '2';ebcdic[243] = '3';ebcdic[244] = '4';
	ebcdic[245] = '5';ebcdic[246] = '6';ebcdic[247] = '7';ebcdic[248] = '8';ebcdic[249] = '9';

	ebcdic[129] = 'a';ebcdic[130] = 'b';ebcdic[131] = 'c';ebcdic[132] = 'd';ebcdic[133] = 'e';
	ebcdic[134] = 'f';ebcdic[135] = 'g';ebcdic[136] = 'h';ebcdic[137] = 'i';

	ebcdic[145] = 'j';ebcdic[146] = 'k';ebcdic[147] = 'l';ebcdic[148] = 'm';ebcdic[149] = 'n';
	ebcdic[150] = 'o';ebcdic[151] = 'p';ebcdic[152] = 'q';ebcdic[153] = 'r';

	ebcdic[162] = 's';ebcdic[163] = 't';ebcdic[164] = 'u';ebcdic[165] = 'v';ebcdic[166] = 'w';
	ebcdic[167] = 'x';ebcdic[168] = 'y';ebcdic[169] = 'z';

	ebcdic[193] = 'A';ebcdic[194] = 'B';ebcdic[195] = 'C';ebcdic[196] = 'D';ebcdic[197] = 'E';
	ebcdic[198] = 'F';ebcdic[199] = 'G';ebcdic[200] = 'H';ebcdic[201] = 'I';

	ebcdic[209] = 'J';ebcdic[210] = 'K';ebcdic[211] = 'L';ebcdic[212] = 'M';ebcdic[213] = 'N';
	ebcdic[214] = 'O';ebcdic[215] = 'P';ebcdic[216] = 'Q';ebcdic[217] = 'R';

	ebcdic[226] = 'S';ebcdic[227] = 'T';ebcdic[228] = 'U';ebcdic[229] = 'V';ebcdic[230] = 'W';
	ebcdic[231] = 'X';ebcdic[232] = 'Y';ebcdic[233] = 'Z';


	string input;
	char output[4096] = {0};
	int n1, n2, n3, ioutput;

	while(getline(cin, input))
	{
		//cout << "read = " << input << endl;
		ioutput = 0;
		for(int i = 0; i < input.size(); i++)
		{
			n1 = input[i++] - '0';
			n2 = input[i++] - '0';
			n3 = input[i++] - '0';

			output[ioutput++] = ebcdic[ n1*64 + n2*8 + n3];
		}

		output[ioutput] = 0;
		cout << output << endl;
	}

	return 0;
}