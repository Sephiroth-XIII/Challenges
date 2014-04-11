#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		vector<vector<int> > A(N);

		for (int i = 0; i < N; ++i)
		{
			vector<int> temp(N);
			for (int j = 0; j < N; ++j)
			{
				cin >> temp[j];
			}
			A[i] = temp;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if(i > 0 && j > 0)
					A[i][j] += max(A[i-1][j],A[i][j-1]);
				else if(i > 0)
					A[i][j] += A[i-1][j];
				else if(j > 0)
					A[i][j] += A[i][j-1];
			}
		}
		cout << setprecision(6) << fixed;
		(A[N-1][N-1] >=0 ? cout << double(A[N-1][N-1])/double(2*N-3) : cout << "Bad Judges") << "\n";
	}
	return 0;
}