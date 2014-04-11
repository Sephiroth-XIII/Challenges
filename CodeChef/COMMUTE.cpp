#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		int start = 0,x,l,f;
		for(;N--;)
		{
			cin >> x >> l >> f;
			int s = x;
			while(s < start)
				s += f;
			start = s; 
			start += l;
		}
		cout << start <<"\n"; 
	}
}