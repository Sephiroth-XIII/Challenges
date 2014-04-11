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

		int b = 1;
		bool flag = true;
		for(;N--;)
		{
			int L;
			cin>>L;
			if((N == 0 && L != b) || (N > 0 && L > b))
			{
				flag = false;
				break;
			}
			b -= L;
			b *= 2;
		}
		flag ? cout<<"Yes\n" : cout<<"No\n";
	}
	return 0;
}