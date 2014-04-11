#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

using namespace std;

const int M = 1000000007;

unsigned long long pow(unsigned long long n)
{
	if(n == 0)
		return 1;
	unsigned long long p = pow(n/2);
	p = (p*p)%M;
	if(n&1)
		p = (p*2)%M;
	return p%M;
}

unsigned long long bitToInt(bitset<20> N)
{
	unsigned long long ull;
	ostringstream oss;
	oss << N;
	string s = oss.str();
	istringstream iss(s);
	iss >> ull;
	return ull;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		unsigned long long N;
		cin >> N;
		bitset<20> B(N);
		N = bitToInt(B);
		unsigned long long ans = pow(N);
		cout << (ans*ans)%M << "\n";
	}
	return 0;
}