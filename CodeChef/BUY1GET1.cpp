#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		string J;
		cin>>J;

		map<char,int> charCount;
		for (int i = 0; i < J.size(); ++i)
		{
			if(charCount.find(J[i]) == charCount.end())
				charCount[J[i]] = 0;
			++charCount[J[i]];
		}

		int cost = 0;
		for (map<char,int>::iterator i = charCount.begin(); i != charCount.end() ; ++i)
		{
			cost += i->second / 2;
			cost += i->second % 2;
		}

		cout<<cost<<"\n";
	}
	return 0;
}