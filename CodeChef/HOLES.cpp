#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		string s;
		cin>>s;
		int count = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i]=='A' || s[i]=='D' || s[i] == 'O' || s[i] == 'P' || s[i] == 'R' || s[i] == 'Q')
				count++;
			else if(s[i] == 'B')
				count+=2;
		}
		cout<<count<<"\n";
	}
	return 0;
}