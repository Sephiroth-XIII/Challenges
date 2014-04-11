#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N,A,B;
		cin>>N>>A>>B;

		bitset<32> a(A);
		bitset<32> b(B);
		bitset<32> c;
		int count = (a.count() + b.count() <= N ? a.count() + b.count() : N - a.count() + N - b.count());
		for (int i = N-1; i >= N-count; --i)
			c.set(i);
		cout<<c.to_ulong()<<"\n";
	}
}