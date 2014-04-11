#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,M;
		cin >> N >> M;

		cout << 1 + gcd(N-1,M-1) << "\n";
	}
	return 0;
}