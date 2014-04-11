#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubsetSum(vector<int> B, int n, int sum)
{
	bool subset[n+1][sum+1];
	for (int i = 0; i <= n ; ++i)
	{
		subset[i][0] = true;
	}
	for (int i = 1; i <= sum; ++i)
	{
		subset[0][i] = false;		
	}
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <= sum; ++j)
		{
			subset[i][j] = subset[i-1][j] || (B[i-1] <= j && subset[i-1][j-B[i-1]]);
		}
	}
	return subset[n][sum];
}

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N,S;
		cin>>N>>S;

		vector<int> B(N);

		for (int i = 0; i < N; ++i)
		{
			cin>>B[i];
		}
		isSubsetSum(B,B.size(),S)?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}