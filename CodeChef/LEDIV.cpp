#include <iostream>
#include <cmath>

using namespace std;

int GCD(int a, int b)
{
	if( b == 0 )
		return a;
	return GCD(b, a % b); 
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		int gcd = 0;
		for(;N--;)
		{
			int C;
			cin >> C;
			gcd = GCD(C,gcd);
		}

		if(gcd != 1)
		{
			for(int i = 2; i <= sqrt(gcd); i++)
				if(gcd % i == 0)
				{
					gcd = i;
					break;
				}
		}

		gcd == 1 ? cout << "-1\n" : cout << gcd << "\n";
	}
	return 0;
}