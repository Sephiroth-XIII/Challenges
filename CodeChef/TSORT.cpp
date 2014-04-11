#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio (false);
	int T;
	cin >> T;

	vector<int> N(T);
	for(int i = 0; i < T; i++)
		cin>>N[i];
	sort(N.begin(),N.end());
	for(int i = 0; i < T; i++)
		cout<<N[i]<<"\n";
	return 0;
}