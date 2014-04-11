#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		vector<unsigned long long> A(3);
		cin >> A[0] >> A[1] >> A[2];
		sort(A.begin(), A.end());

		A[0] %= 1000000007;
		A[1] = (A[1]-1)%1000000007;
		A[2] = (A[2]-2)%1000000007;

		cout << (((A[0]*A[1])%1000000007)*A[2])%1000000007 << "\n";
	}
	return 0;
}