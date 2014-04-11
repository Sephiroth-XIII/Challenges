#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string S;
		cin >> S;

		int count = 1+S.size();
		
		for (int i = 1; i < S.size(); ++i)
			count += S[i] - S[i-1] < 0 ? 26 - (S[i-1] - S[i]) : S[i] - S[i-1];

		count <= 11*S.size() ? cout << "YES\n" : cout << "NO\n";
 	}
 	return 0;
}