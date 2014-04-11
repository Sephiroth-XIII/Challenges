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
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		int A,B;
		for (int i = 0; i < N; ++i)
		{
			cin >> A;
			if(i == 0)
				B = A;
			else 
				B = gcd(A,B);
		}
		cout<<B<<"\n";
	}
	return 0;
}