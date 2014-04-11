#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin>>N;

		map<string,int> vote;
		for (int i = 0; i < N; ++i)
		{
			string name;
			char v;
			cin>>name>>v;
			vote[name] = v == '+'?1:-1;
		}

		int count = 0;
		for(map<string,int>::iterator i = vote.begin(); i != vote.end(); i++)
		{
			count += i->second;
		}
		cout<<count<<"\n";
	}
	return 0;
}