#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;
		unsigned long long count = 0;
		unsigned long long p = 5;
		while(p <= 1000000000 && p <= N)
		{
			count += N/p;
			p *= 5; 
		}
		cout<<count<<"\n";
	}
	return 0;
}