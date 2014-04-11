#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

bool compare(pair<int,int> A, pair<int,int> B)
{
	return A.first == B.first ? A.second > B.second : A.first < B.first;
}

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		vector<pair<int,int> > A(N);
		for(int i = 0; i < N; i++)
			cin>>A[i].first>>A[i].second;
		sort(A.begin(),A.end(),compare);
	
		double distance = 0.0;
		for(int i = 1; i < N; i++)
			distance += sqrt(pow(A[i].first-A[i-1].first,2)+pow(A[i].second-A[i-1].second,2));
		cout<<setprecision(2)<<fixed<<distance<<"\n";
	}
	return 0;
}