#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > a;
vector<int> mark;
int cnt;

void dfs(int u)
{
	++cnt;
	mark[u] = 1;

	for(vector<int>::iterator v = a[u].begin(); v != a[u].end(); ++v)
		if(!mark[*v])
			dfs(*v);
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,M;
		cin >> N >> M;

		a = vector<vector<int> >(N);
		for (int i = 0; i < M; ++i)
		{
			int u,v;
			cin >> u >> v;
			--u,--v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		int res = 0;
		int ways = 1;
		mark = vector<int>(N,0);

		for(int u = 0; u < N; ++u)
		{
			if(mark[u])
				continue;
			++res;
			cnt = 0;
			dfs(u);
			ways = (long long)cnt * ways % 1000000007;
		}
		cout<<res << " " << ways << "\n";
	}
	return 0;
}