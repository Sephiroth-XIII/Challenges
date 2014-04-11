#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		vector<int> A(10);
		for (int i = 0; i < 10; ++i)
		{
			cin>>A[i];
		}
		int n = min_element(A.begin()+1,A.end()) - A.begin();
		int maxTens = pow(10,A[0]+1), maxNonTens=0;
		do
		{
			maxNonTens*=10;
			maxNonTens+=n;
		}while(A[n]--);
		cout<<min(maxTens,maxNonTens)<<"\n";
	}
	return 0;
}