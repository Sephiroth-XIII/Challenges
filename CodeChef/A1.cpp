#include <iostream>
#include <vector>

using namespace std;

/*bool hasSubset(vector<int> M, int S , int N)
{
	if(S == 0)
		return true;
	if(S != 0 && N == 0)
		return false;
	if(M[N-1] > S)
		return hasSubset(M,S,N-1);
	else
		return hasSubset(M,S,N-1) || hasSubset(M,S-M[N-1],N-1);
}*/

bool hasSubset(vector<int> M, int S, int N)
{
	int subset[S+1][M.size()+1];

	for (int i = 0; i <= M.size(); ++i)
	{
		subset[0][i] = 1;
	}
	for (int i = 1; i <= S; ++i)
	{
		subset[i][0] = 0;
	}

	for (int i = 1; i <= S; ++i)
	{
		for (int j = 1; j <= M.size(); ++j)
		{
			subset[i][j] = (subset[i][j-1] || (M[j-1] <= i && subset[i-M[j-1]][j-1]));
		}
	}
	return subset[S][M.size()];
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,S;

		cin >> N >> S;

		vector<int> M(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> M[i];
		}

		hasSubset(M,S,N) ? cout << "Yes\n" : cout << "No\n";
	}
	return 0;
}