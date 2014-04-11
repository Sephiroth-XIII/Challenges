#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	vector<int> A;
	for (int i = 0; i < 12; ++i)
	{
		A.push_back(pow(2,i));
	}

	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		int count = 0;
		for (int i = 11; i >= 0 ; --i)
		{
			count += (N/A[i]);
			N -= (N/A[i])*A[i];
		}
		cout<<count<<"\n";
	}
	return 0;
}
