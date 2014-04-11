#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;
		string S,S1="";
		cin >> S;

		S1 = S;
		for (int i = 0; i < S.size(); ++i)
			if((i > 0 && S[i-1]=='1') || S[i]=='1' || (i < S.size()-1 && S[i+1] == '1'))
				S1[i] = '1';
			else
				S1[i] = '0';
		cout<<count(S1.begin(), S1.end(), '0')<<"\n";
	}
	return 0;
}