#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,M;
		cin >> N >> M;

		vector<string> G(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> G[i];
		}

		int count = 0;
		for (int s = 1; s < N; ++s)
			for (int i = 0; i < N-s; ++i)
				for (int j = 0; j < M-s; ++j)
					if(G[i][j] == G[i+s][j] && G[i][j] == G[i][j+s] && G[i][j] == G[i+s][j+s])
						++count;

		cout << count << "\n";
	}
	return 0;
}