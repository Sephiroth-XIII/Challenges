#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio (false);
	int n,k,x;
	cin>>n>>k;

	int count = 0;
	for(;n--;)
	{
		cin>>x;
		if(x%k==0)
			++count;
	}
	cout<<count<<"\n";
	return 0;
}