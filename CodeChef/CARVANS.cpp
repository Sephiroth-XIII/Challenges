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

		vector<int> A(N);
		int slowCount = 0;
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
			if(i > 0)
			{
				if(A[i] > A[i-1])
				{
					A[i] = A[i-1];
					++slowCount;
				}
			}
		}
		cout<< N - slowCount<<"\n"; 
	}
	return 0;
}