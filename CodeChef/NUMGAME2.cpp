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
		N%4 == 1 ? cout<<"ALICE\n" : cout<<"BOB\n";
	}
	return 0;
}