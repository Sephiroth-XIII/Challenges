#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string M,W;
		cin >> M >> W;

		if(M.size() == W.size())
		{
			M == W ? cout << "YES\n" : cout << "NO\n";
		}
		else if(M.size() > W.size())
		{
			int i,j;
			for (i = 0,j = 0; i < M.size(); ++i)
			{
				if(M[i] == W[j])
					++j;
			}
			j == W.size() ? cout << "YES\n" : cout << "NO\n";
		}
		else
		{
			int i,j;
			for (i = 0,j = 0; i < W.size(); ++i)
			{
				if(W[i] == M[j])
					++j;
			}
			j == M.size() ? cout << "YES\n" : cout << "NO\n";
		}
	}
	return 0;
}