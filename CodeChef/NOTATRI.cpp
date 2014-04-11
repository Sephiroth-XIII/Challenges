#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;

	while(cin>>N && N != 0)
	{
		vector<int> sticks(N);
		for (int i = 0; i < N; ++i)
			cin >> sticks[i];
		sort(sticks.begin(),sticks.end());

		int count = 0;
		for (int i = N-1; i >= 2 ; --i)
		{
			int l = 0;
			int r = i - 1;
			while(l < r)
			{
				if(sticks[l] + sticks[r] < sticks[i])
				{
					count += r-l;
					l++;
				}
				else
					r--;
			}
		}
		cout<<count<<"\n";
	}	
	return 0;
}