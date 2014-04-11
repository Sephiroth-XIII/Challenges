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
		N&1?cout<<"BOB\n":cout<<"ALICE\n";
	}
	return 0;
}