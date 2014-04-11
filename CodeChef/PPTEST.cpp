#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,W;
		cin >> N >> W;

		vector<pair<int,int> > A(N);
		for (int i = 0; i < N; ++i)
		{
			int C,P;
			cin >> C >> P >> A[i].second;
			A[i].first = C*P;
		}

		vector<int> G(W+1,-1);
		G[0] = 0;

		for (int i = 0; i < N; i++)
			for (int j = W; j >= A[i].second; j--)
				if(G[j - A[i].second] >= 0) 
					G[j] = max(G[j],G[j-A[i].second]+A[i].first);

		int res = 0;
		for (int i = 1; i <= W; ++i)
			res = max(res,G[i]);

		cout << res << "\n";
	}
	return 0;
}