#include <iostream>
#include <string>
#include <vector>
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

		vector<string> B(N);
		int x,y;
		for (int i = 0; i < N; ++i)
		{
			cin >> B[i];
		}

		int score[N][N];

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				score[i][j] = (B[i][j] == 'P' && i > x && j > y? 1 : 0);

		int i,j;
		for(j = N-1; j >= 0; j--)
		{
			for(i = 0; i < N; i++)
			{
				int r=0;
				if(j+1<N && i+2<N)
					r=max(r,score[i+2][j+1]);
				if(j+1<N && i-2>=0)
					r=max(r,score[i-2][j+1]);				
				if(j+2<N && i+1<N)
					r=max(r,score[i+1][j+2]);
				if(j+2<N && i-1>=0)
					r=max(r,score[i-1][j+2]);
				score[i][j] = r + (B[i][j] == 'P' ? 1 : 0);
				
				if(B[i][j] == 'K')
					break;
			}
			if(i<N) 
				break ;
		}

		cout << score[i][j] <<"\n";
	}
	return 0;
}