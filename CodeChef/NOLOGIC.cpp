#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	cin.ignore();
	for(;T--;)
	{
		string S;
		getline(cin,S);
		transform(S.begin(),S.end(),S.begin(),::tolower);
		bitset<26> C;
		for(int i = 0; i < S.size(); i++)
			if(S[i] >= 'a' && S[i] <= 'z')
				C.set(S[i] - 'a');

		if(C.count() == 26)
			cout << "~";
		else
			for(int i = 0 ; i < 26; i++)
				if(!C[i])
					cout << char(i+'a');
		cout << "\n";
	}
	return 0;
}