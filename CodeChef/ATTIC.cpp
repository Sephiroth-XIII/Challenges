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

		int cur = 0, L = 1, days = 0;
		for(int i = 0; i < S.size(); i++)
		{
			cur++;
			if(S[i] == '#')
			{
				if(cur > L)
				{
					L = cur;
					days++;
				}
				cur = 0;
			}
		}
		cout << days << "\n";
	}
	return 0;
}