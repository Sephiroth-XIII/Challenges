#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		string J,S;
		cin>>J>>S;

		set<char> jewel;
		for (int i = 0; i < J.size(); ++i)
			jewel.insert(J[i]);

		int count = 0;
		for (int i = 0; i < S.size(); ++i)
			if(jewel.find(S[i]) != jewel.end())
				++count;

		cout<<count<<"\n";
	}
	return 0;
}