#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N,D;
	cin >> N >> D;

	vector<int> A(N);

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A.begin(),A.end());

	int pairs = 0;

	for (int i = 0; i < N-1; )
		if(A[i+1] - A[i] <= D)
			++pairs, i+=2;
		else
			++i;

	cout << pairs << "\n";
	return 0;
}