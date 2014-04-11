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
		vector<int> pies(N),limits(N);
		for (int i = 0; i < N; ++i)
		{
			cin>>pies[i];
		}
		for (int i = 0; i < N; ++i)
		{
			cin>>limits[i];
		}
		sort(pies.begin(), pies.end());
		sort(limits.begin(), limits.end());
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if(pies[i] <= limits[j])
				{
					limits[j] = -1;
					++count;
					break;
				}
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}