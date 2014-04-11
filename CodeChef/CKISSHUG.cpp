#include <iostream>

using namespace std;

#define MOD 1000000007

long long power(long long a,long long b)
{
	long long r;
	if(b == 0)
		return 1;
	r = power(a,b/2);
	r = (r*r)%MOD;
	if(b%2)
		r = (r*a)%MOD;
	return r;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		long long n1,n2,res;

		cin >> N;
		N++;
		n1 = N/2 , n2 = N - n1;
		res = power(2,n1) + power(2,n2) - 2;
		cout << res % MOD << "\n";
	}
	return 0;
}