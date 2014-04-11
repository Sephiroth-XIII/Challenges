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
		int n = N+1;
		bool flag = true;
		for(;n--;)
		{
			if(n%7 == 0 && (N-n)%4 == 0)
			{
				cout<<n<<"\n";
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"-1\n";
	}
	return 0;
}