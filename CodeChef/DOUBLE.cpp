#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		N&1?cout<<N-1<<"\n":cout<<N<<"\n";
	}
	return 0;
}