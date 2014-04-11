#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int G;
		cin>>G;

		for(;G--;)
		{
			int I,N,Q,H=0;
			cin>>I>>N>>Q;
			H = I == 1 ? N/2 : N/2 + N%2;
			Q == 1 ? cout<<H<<"\n" : cout<<N-H<<"\n";
		}
	}
	return 0;
}