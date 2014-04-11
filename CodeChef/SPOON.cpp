#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int R,C;
		cin >> R >> C;
		
		vector<string> S(R);
		bool isSpoon = false;
		for (int i = 0; i < R; ++i)
		{
			cin >> S[i]; 
			transform(S[i].begin(),S[i].end(),S[i].begin(),::tolower);
			if(S[i].find("spoon") != string::npos)
				isSpoon = true;
		}

		if(isSpoon)
			cout << "There is a spoon!\n";
		else
		{
			for (int i = 0; i < C; ++i)
			{
				string s = "";
				for (int j = 0; j < R; ++j)
				{
					s += S[j][i];
				}
				if(s.find("spoon") != string::npos)
				{
					isSpoon = true;
					break;
				}
			}
			isSpoon ? cout << "There is a spoon!\n" : cout << "There is indeed no spoon!\n";
		}
	}
	return 0;
}