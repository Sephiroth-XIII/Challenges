#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int N1,N2,N3;
	cin>>N1>>N2>>N3;

	map<int,int> voteID;
	for (int i = 0; i < N1+N2+N3; ++i)
	{
		int x;
		cin >> x;

		if(voteID.find(x) == voteID.end())
			voteID[x] = 0;
		++voteID[x];
	}
	vector<int> voters;
	for (map<int,int>::iterator i = voteID.begin(); i != voteID.end(); ++i)
	{
		if(i->second >= 2)
			voters.push_back(i->first);
	}
	cout<<voters.size()<<"\n";
	for (int i = 0; i < voters.size(); ++i)
	{
		cout<<voters[i]<<"\n";
	}
	return 0;
}