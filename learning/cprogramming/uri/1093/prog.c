// it helped: https://en.wikipedia.org/wiki/Gambler%27s_ruin

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define prf printf
#define scf scanf

int main(void)
{
	int EV1, EV2, AT, D;
	double P_Q[6], // = P / Q, where P is the probability of V1 to win and Q is the probability of V2 to win
	P1, // probability of V1 to lose
	dEV1, dEV2; // double versions of EV1 and EV2, that will divide D

	P_Q[1] = 1.0 / 5.0; // AT = 1
	P_Q[2] = 2.0 / 4.0; // AT = 2
	P_Q[3] = 3.0 / 3.0; // AT = 3 -> both have same chance to win
	P_Q[4] = 4.0 / 2.0; // AT = 4
	P_Q[5] = 5.0 / 1.0; // AT = 5

	while(scf("%d %d %d %d", &EV1, &EV2, &AT, &D) != EOF)
	{
		if((EV1 | EV2 | AT | D) == 0)
			break;
		// prf("EV1 = %d, EV2 = %d, AT = %d, D = %d\n", EV1, EV2, AT, D);
		// prf("P_Q[%d] = %f\n", AT, P_Q[AT]);

		// Both have same chance to win
		if(AT == 3)
		{
			if(EV1 <= D && EV2 <= D)
				P1 = 0.5;
			else while(EV1 <= )
				P1 = EV2 / (double)(EV1 + EV2);
			//prf("0.P1 = %f\n", P1);
		}
		else
		{
			dEV1 = ceil(EV1 / (double)D);
			dEV2 = ceil(EV2 / (double)D);
			P1 = (1 - pow(P_Q[AT], dEV2)) / (1 - pow(P_Q[AT], dEV1 + dEV2));
			//prf("1.P1 = %f\n", P1);
		}

		prf("%.1f\n", (1.0 - P1) * 100.0);
	}

	return 0;
}
