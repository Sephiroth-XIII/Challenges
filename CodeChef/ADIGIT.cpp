#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;

	vector<long long> A(N),X(10,0),C(10,0),S(N+1,0);

	for (int i = 0; i < N; ++i)
	{
		char c;
		cin >> c;
		A[i] = c-'0';
		
		int countBefore = accumulate(C.begin(), C.begin()+A[i],0ll);
		int countAfter = accumulate(C.begin()+A[i]+1,C.end(),0ll);
		long long total = (countBefore*A[i]-accumulate(X.begin(),X.begin()+A[i],0ll)) + (accumulate(X.begin()+A[i]+1,X.end(),0ll)-A[i]*countAfter);
		S[i] = total;
		X[A[i]] += A[i];
		++C[A[i]];
	}

	for (int i = 0; i < M; ++i)
	{
		int x;
		cin >> x;
		cout << S[x-1] << "\n";
	}


	return 0;
}