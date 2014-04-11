#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	bitset<10001> isPrime;
	isPrime.set();
	isPrime.reset(0);
	isPrime.reset(1);

	for (int i = 2; i <= sqrt(10001) ; ++i)
		if(isPrime[i])
			for (int j = i*i; j <= 10000; j+=i)
				isPrime.reset(j);


	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		int nCopy = N;
		vector<int> divisors(1,1);
		for (int i = 2; i <= min(10000,int(sqrt(nCopy))) && N > 1; ++i)
		{
			if(isPrime[i])
			{
				int p = i*i > N ? N : i;
				if(N % p == 0)
				{
					int deg = 0;
					while(N % p == 0)
					{
						++deg;
						N /= p;
					}
					int limit = divisors.size();
					for (int k = 0; k < limit; ++k)
					{
						int divisor = divisors[k];
						for (int j = 0; j < deg; ++j)
						{
							divisor *= p;
							divisors.push_back(divisor);
						}
					}
				}
			}
		}
		N = nCopy;
		int ans = N-1;
		for (int i = 0; i < divisors.size(); ++i)
		{
			int d = divisors[i];
			ans = min(ans, abs(N/d - d));
		}
		cout<< ans << "\n";
	}
	return 0;
}