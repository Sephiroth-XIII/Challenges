#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool perfectSq(long long j)
{
	while(j)
	{
		int x = j%10;
		j/=10;
		if(x != 0 && x != 1 && x != 4 && x != 9)
			return false;
	}
	return true;
}

int main()
{
	vector<long long> perfect;

	for (long long i = 1; i <= 100000 ; ++i)
	{
		long long j = i*i;
		if(perfectSq(j))
			perfect.push_back(j);
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		long long a,b,count=0;
		cin >> a >> b;

		for (int j = 0; j < perfect.size() && perfect[j] <= b; ++j)
		{
			if(perfect[j] >= a)
				++count;
		}
		cout << count << "\n";
	}
	return 0;

}