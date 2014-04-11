#include <iostream>
#include <string>

using namespace std;

int mod2(string B, int A)
{
	int N = 0;
	for (int i = 0; i < B.size(); ++i)
	{
		N*=10;
		N+=int(B[i]-'0');
		N%=A;
	}
	return N;
}

int gcd2(int a, int b)
{
	if(b==0)
		return a;
	return gcd2(b,a%b);
}

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int A;
		string B;
		cin>>A>>B;
		if(A == 0)
			cout<<B<<"\n";
		else
		{
			int b = mod2(B,A);
			cout<<gcd2(A,b)<<"\n";
		}
	}
	return 0;
}