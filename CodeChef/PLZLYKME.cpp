#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		double L,D,S,C;
		cin >> L >> D >> S >> C;

		if(D == 1)
		{
			if(S >= L)
				cout << "ALIVE AND KICKING\n";
			else
				cout << "DEAD AND ROTTING\n";
		}
		else
		{
			if(pow(L,1.0/(D-1)) <= (C+1)*pow(S,1.0/(D-1)))
				cout << "ALIVE AND KICKING\n";
			else
				cout << "DEAD AND ROTTING\n";
		}
	}
	return 0;
}