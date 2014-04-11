#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solve(vector<int> I)
{
	int total = accumulate(I.begin(), I.end(), 0);

	if(total % I.size() != 0)
		return -1;

	int count = 0;
	int minI = min_element(I.begin(), I.end())-I.begin(), maxI = max_element(I.begin(), I.end())-I.begin();
	while(I[minI] != I[maxI])
	{
		int min = I[minI],max = I[maxI];
		I[minI] += ceil(float(max-min)/2);
		I[maxI] -= ceil(float(max-min)/2);
		minI = min_element(I.begin(), I.end())-I.begin(); 
		maxI = max_element(I.begin(), I.end())-I.begin();
		++count;
	}
	return count;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		vector<int> I(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> I[i];
		}

		cout << solve(I) << "\n";
	}
}