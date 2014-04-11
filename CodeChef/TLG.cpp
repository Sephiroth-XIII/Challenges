#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int player,lead=0,A,B,a=0,b=0;
	for(;T--;)
	{
		cin>>A>>B;
		A+=a;
		B+=b;
		if(A>B && A-B>lead)
		{
			lead = A-B;
			player = 1;
		}
		else if (B>A && B-A>lead)
		{
			lead = B-A;
			player = 2;
		}
		a=A;
		b=B;
	}
	cout<<player<<" "<<lead<<"\n";
	return 0;
}