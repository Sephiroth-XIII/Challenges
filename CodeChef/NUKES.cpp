#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A,N,K;
	cin>>A>>N>>K;

	while(K--)
	{
		cout<<A%(N+1)<<" ";
		A/=(N+1);
	}
	return 0;
}