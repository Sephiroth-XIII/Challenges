#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		string S,S1;
		cin >> N >> S;
		S1 = S;
		for (int i = 0; i < pow(2,N); ++i)
		{
			bitset<32> B(i);
			bitset<32> A;
			for (int j = 0; j < N ; ++j)
				A[j] = B[N-1-j];
			S1[A.to_ulong()] = S[i];
		}
		cout<<S1<<"\n";
	}
	return 0;
}