#include <iostream>
#include <numeric>
#include <climits>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;
		int MIN = INT_MAX; 
		unsigned long long total = 0;

		for(;N--;)
		{
			int x;
			cin >> x;
			total += x;
			if(x < MIN)
				MIN = x;
		}

		total -= MIN;

		cout << total*MIN << "\n";
	}
	return 0;
}