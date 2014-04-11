#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	return b ? gcd(b,a%b) : a;
}

unsigned long long NCR(unsigned long long N, unsigned long long K)
{
	if(K > N)
		return 0;

	K = min(N-K,K);

	unsigned long long p = 1;
	for (unsigned long long i = 1; i <= K ; ++i)
	{
		unsigned long long g = gcd(p,i);
		p /= g;
		p *= (N-i+1)/(i/g);
	}
	return p;
}

int main()
{
	int T;
	cin >> T;
	for(;T--;)
	{
		unsigned long long N,K;
		cin >> N >> K;
		cout << NCR(N,K) << "\n";
	}
	return 0;
}