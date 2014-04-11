#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	bitset<2100> primes;
	primes.set();
	primes.reset(0);
	primes.reset(1);
	for (int i = 2; i <= sqrt(2100); ++i)
	{
		if(primes[i])
		{
			for (int j = i*i; j < 2100; j+=i)
			{
				primes.reset(j);
			}
		}
	}
	
	int T;
	cin >> T;

	for(;T--;)
	{
		int x,y,z;
		cin >> x >> y;

		for (z = 1; !primes[x+y+z] ; ++z);
		cout << z << "\n";
	}
	return 0;
}