#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int a,b;
		cin >> a >> b;
		if(a == b)
		{
			cout << "0\n";
			continue;
		}
		if(a < b)
			swap(a,b);

		int count = 0;
		vector<int> bs;
		while(b != 0)
			bs.push_back(b),b/=2;
		while(a!=0)
		{
			if(find(bs.begin(), bs.end(), a) != bs.end())
			{
				for (int i = 0; i < bs.size(); ++i)
				{
					if(bs[i] == a)
					{
						count += i;
						break;
					}
				}
				break;
			}
			a/=2;
			++count;
		}
		
		cout << count << "\n";
	}
	return 0;
}