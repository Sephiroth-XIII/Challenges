#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		vector<int> A(N);
		int GCD=1001;
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
			if(i>0 && gcd(A[0],A[i]) < GCD)
				GCD = gcd(A[0],A[i]);
		}
		for (int i = 0; i < N; ++i)
		{
			cout<<A[i]/GCD<<" ";
		}
		cout<<"\n";
	}
	return 0;
}