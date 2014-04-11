#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int P,S;
		cin>>P>>S;
		float l = (P - (sqrt(P*P - 24*S)))/12;
		float h = (P/4)-(2*l);
		cout<<setprecision(2)<<fixed<<l*l*h<<"\n";
	}
	return 0;
}