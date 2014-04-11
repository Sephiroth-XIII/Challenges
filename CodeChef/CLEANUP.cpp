#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N,K;
		cin>>N>>K;
		bitset<1001> jobs;
		jobs.set();
		for (int i = 0; i < K; ++i)
		{
			int x;
			cin>>x;
			jobs.reset(x);
		}
		for (int i = 1,j = 0; i <= N; ++i)
		{
			if(jobs[i])
			{
				if(!(j&1))
				{
					cout<<i<<" ";
					jobs.reset(i);
				}
				++j;
			}
		}
		cout<<"\n";
		for (int i = 1; i <= N; ++i)
		{
			if(jobs[i])
			{
				cout<<i<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}