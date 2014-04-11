#include <iostream>
#include <string>
#include <cmath>
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

		if(S.size() != 5)
			cout << "Error\n";
		else
		{
			if(S[0]>='a' && S[0]<='h' && S[3]>='a' && S[3]<='h' && S[1]>='1' && S[1]<='8' && S[4]>='1' && S[4]<='8' && S[2]=='-')
			{
				if((abs(S[0]-S[3]) == 2 && abs(S[1]-S[4]) == 1) || (abs(S[0]-S[3]) == 1 && abs(S[1]-S[4]) == 2))
					cout << "Yes\n";
				else
					cout << "No\n";
			}
			else
				cout << "Error\n";
		}
	}
	return 0;
}