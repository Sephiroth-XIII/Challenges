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
		cin>>N;

		vector<int> A(N);
		for (int i = 0; i < N; ++i)
			cin>>A[i];

		int local = 0, global = 0;
		for (int i = 1; i < N; ++i)
			if(A[i-1] > A[i])
				++local;

		for(int i = 0; i < N-1; ++i)
			for(int j = i+1; j < N; ++j)
				if(A[i] > A[j])
					++global;

		global == local ? cout<<"YES\n" : cout<<"NO\n";
	}		
	return 0;
}