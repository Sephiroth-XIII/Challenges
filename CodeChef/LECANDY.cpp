#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N,C;
		cin>>N>>C;
		for (int i = 0; i < N; ++i)
		{
			int X;
			cin>>X;
			C -= X;
		}
		C>=0?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}