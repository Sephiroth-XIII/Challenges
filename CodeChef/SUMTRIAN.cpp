#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		vector<vector<int> > triangle;
		for(int i = 0; i < N; i++)
		{
			int x;
			vector<int> temp;
			for(int j = 0; j <=i; j++)
			{
				cin>>x;
				temp.push_back(x);
			}
			triangle.push_back(temp);
		}

		for(int i = N-2 ; i >=0 ; i--)
		{
			for(int j = 0; j <=i ; j++)
			{
				triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]); 
			}
		}
		cout<<triangle[0][0]<<"\n";
	}
	return 0;
}