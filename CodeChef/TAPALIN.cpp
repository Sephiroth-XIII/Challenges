#include <iostream>

using namespace std;

typedef long long LL;
const int MOD = 1000000007;

int powmod(int a, int n)
{
	int p = 1;
	for(;n;)
	{
		if(n%2) p = LL(p)*a%MOD;
		if(n/=2) a = LL(a)*a%MOD;
	}
	return p;
}

int calc(int N)
{
	int inv25 = powmod(25, MOD -2);
	int k = (N+1)/2;
	int p26 = powmod(26,k);
	int ans = 52LL * (p26 - 1) % MOD * inv25 % MOD;
	if(N%2)
		ans = (ans + MOD - p26) % MOD;
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for(;T--;)
	{
		int N;
		cin >> N;

		cout << calc(N) << "\n";
	}
	return 0;
}