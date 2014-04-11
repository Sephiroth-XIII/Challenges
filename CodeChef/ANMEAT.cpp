#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(unsigned long long A, unsigned long long B)
{
	return A > B;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		unsigned long long N,M;
		cin >> N >> M;

		vector<unsigned long long> P(N);
		unsigned long long total = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> P[i];
			total += P[i];
		}

		if(total < M)
		{
			cout << "-1\n";
		}
		else
		{
			sort(P.begin(), P.end(), compare);
			unsigned long long total = 0;
			for (int i = 0; i < N; ++i)
			{
				total += P[i];
				if(total >= M)
				{
					cout << i+1 <<"\n";
					break;
				}
			}
		}
	}
	return 0;
}