#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,K;
		cin >> N >> K;

		vector<int> W(N);
		int total = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> W[i];
			total += W[i];
		}

		sort(W.begin(), W.end());

		int w1 = 0,w = 0;
		for (int i = 0; i < K; ++i)
			w += W[i];
		for (int i = N-1 ; i > N-1-K ; --i)
			w1 += W[i];

		abs(2*w1 - total) >= abs(2*w - total) ? cout << abs(2*w1 - total) << "\n" : cout << abs(2*w - total) << "\n";
	}
	return 0;
}