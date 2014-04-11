#include <iostream>

using namespace std;

int D(int N)
{
	int res = 0;
	while(N)
		res += (N&1 ? N%10 : 2*(N%10)), N/=10 ;
	return res%10;
}

int C(int n)
{
	int res = 0;
	while(n%10)
		res += D(--n);
	return res+45*(n/10);
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		unsigned long long A,B;
		cin >> A >> B;
		cout << C(B+1) - C(A) << "\n";
	}
	return 0;
}