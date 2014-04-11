#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

void calcPro(vector<pair<unsigned long long,bool> > &pro)
{
	for (unsigned long long i = 2; i <= sqrt(500000); ++i)
	{
		for (unsigned long long j = i*i; j <= 500000 ; j+=i)
		{
			pro[j].first*=i;
			if(i != j/i && i != j)pro[j].first*=(j/i);
			if(pro[j].first >= 10000)pro[j].second = true;
			pro[j].first%=10000;
		}
	}
}

string integerToString(pair<unsigned long long,bool> n)
{
	ostringstream oss;
	oss << n.first;
	string s = oss.str();
	if(n.second == true)
		while(s.size() < 4)
			s = '0'+s;
	return (s.size() <= 4 ? s : s.substr(s.size()-4,4));
}

int main()
{
	vector<pair<unsigned long long,bool> > pro(500001,make_pair(1,false));
	calcPro(pro);

	int T;
	scanf("%d",&T);

	for(;T--;)
	{
		int x;
		scanf("%d",&x);
		cout << integerToString(pro[x]) << "\n";
	}
	return 0;
}