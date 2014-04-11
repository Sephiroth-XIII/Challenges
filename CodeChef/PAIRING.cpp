#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (;T--;)
	{
		int N,M;
		cin >> N >> M;
		vector<pair<int,int> > pairs(M);
		bitset<10001> C;
		
		for(int i = 0; i < M; i++)
		{
			cin >> pairs[i].first >> pairs[i].second ;
		}

		vector<int> res;
		for(int i = M-1; i >= 0; i--)
		{
			if(!C[pairs[i].first] && !C[pairs[i].second])
				res.push_back(i),C.set(pairs[i].first),C.set(pairs[i].second);
		}

		sort(res.begin(), res.end());

		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << " ";
		cout << "\n";
	}
	return 0;
}