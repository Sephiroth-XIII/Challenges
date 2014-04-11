#include <iostream>
#include <algorithm>

using namespace std;

long long int distance(long long int n)
{
	if(n < 0)
		return 0;
	return ((n+1)*(n+2)*(n+3))/6;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,A,B,C;
		cin >> N >> A >> B >> C;
		cout << distance(N) - distance(N-A-1) - distance(N-B-1) - distance(N-C-1) + distance(N-A-B-2) + distance(N-A-C-2) + distance(N-C-B-2) - distance(N-A-B-C-3) << "\n";
	}
	return 0;
}