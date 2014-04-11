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

		int count = 0;
		for (int i = 0; i < S.size(); ++i)
			if(S[i] != '4' && S[i] != '7')
				++count;

		cout << count << "\n";
	}
	return 0;
}