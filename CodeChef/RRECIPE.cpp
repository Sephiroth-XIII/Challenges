#include <iostream>
#include <string>
#define MOD 10000009

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string S;
		cin >> S;

		int count;
		if(S.size()&1 && S[S.size()/2]=='?')
			count = 26;
		else
			count = 1;

		for (int i = 0; i < S.size()/2; ++i)
		{
			if(S[i] == '?' && S[S.size()-1-i] == '?')
				count = (count*26)%MOD;
			else if(S[i] != '?' && S[S.size()-1-i] != '?' && S[i] != S[S.size()-1-i])
			{
				count = 0;
				break;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}