#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int B,M;
		cin >> B >> M;

		int N=1,D=1;

		while(--B)
		{
			N = (N+D)%M;
			D = (N+D)%M;
		}

		cout << N%M <<"/" << D%M << "\n";
	}
	return 0;
}