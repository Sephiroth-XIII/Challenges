#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int n,k,p;
		cin >> n >> k >> p;
		
		set<int> D;
		for (int i = 0; i < k; ++i)
		{
			int a,b;
			cin >> a >> b;
			D.insert(a*2-1);
			D.insert(b*2);
		}
		bool flag = true;
		for (int i = 0; i < p; ++i)
		{
			int a,b;
			cin >> a >> b;
			if(D.find(a*2-1) == D.end() || D.find(b*2) == D.end())
				flag = false;
		}
		flag ? cout << "Yes\n" : cout << "No\n";
	}

	return 0;
}