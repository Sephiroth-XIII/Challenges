#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin >> N;

		vector<int> l(N);
		for (int i = 0; i < N; ++i)
			cin >> l[i];
		int K;
		cin >> K;
		int count = 1;
		for (int i = 0; i < N; ++i)
			if(l[i] < l [K-1])
				++count;
		cout<<count<<"\n";
	}
	return 0;
}