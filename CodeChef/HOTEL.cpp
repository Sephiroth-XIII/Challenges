#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> A, pair<int,int> B)
{
	return A.second < B.second;
}

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>> N;

		vector<pair<int,int> > timings(N);
		for (int i = 0; i < N; ++i)
		{
			cin>>timings[i].first;
		}
		for (int i = 0; i < N; ++i)
		{
			cin>>timings[i].second;
		}
		sort(timings.begin(), timings.end(),compare);

		int maxNum = 1;
		for(int j = 0; j < N-maxNum; j++)
		{
			int count = 1,leftTime = timings[j].second;
					
			for (int i = j+1; i < N; ++i)
			{
				if(timings[i].first < leftTime)
				{
					++count;
				}
			}
			if(count > maxNum)
				maxNum = count;
		}
		cout<<maxNum<<"\n";
	}
	return 0;
}