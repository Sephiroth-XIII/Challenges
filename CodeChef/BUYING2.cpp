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
		int MIN = 100, TC = 0;
		for(;N--;)
		{
			int c;
			cin>>c;
			TC += c;
			if(c < MIN)MIN = c;
		}
		(TC/C) > 0 && TC%C < MIN ? cout<<TC/C<<"\n" : cout<<"-1\n";
	}
	return 0;
}