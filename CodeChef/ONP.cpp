#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		string exp,onp;
		cin>>exp;
		vector<char> sym;
		for (int i = 0; i < exp.size(); ++i)
		{
			if(exp[i]=='(')continue;
			if(exp[i] == ')')
			{
				onp+=sym.back();
				sym.pop_back();
			}
			else if (isalpha(exp[i]))
			{
				onp+=exp[i];
			}
			else
			{
				sym.push_back(exp[i]);
			}
		}
		cout<<onp<<"\n";
	}
	return 0;
}