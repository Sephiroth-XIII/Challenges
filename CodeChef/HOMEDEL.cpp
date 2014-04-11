#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int> > adj(N);

	for (int i = 0; i < N; ++i)
	{
		vector<int> temp(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> temp[j];
		}
		adj[i] = temp;
	}

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];

	int M;
	cin >> M;
	for(;M--;)
	{
		int S,G,D;
		cin >> S >> G >> D;
		cout << adj[S][G] + adj[G][D] << " " << adj[S][G] + adj[G][D] - adj[S][D] << "\n";
	}
	return 0;
}