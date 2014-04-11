#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		string S;
		cin >> S;

		vector<int> A(26,0),B(26,0);
		for (int i = 0; i < S.size()/2; ++i)
			++A[S[i]-'a'];

		for (int i = S.size()-1; i > (S.size() & 1 ? S.size()/2 : S.size()/2-1 ) ; --i)
			++B[S[i]-'a'];

		A == B ? cout<<"YES\n" : cout<<"NO\n";
	}
	return 0;
}