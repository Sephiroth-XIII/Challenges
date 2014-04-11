#include <iostream>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long expected = (N*(N+1))/2, recieved = 0;
	for(;N--;)
	{
		long long x;
		cin >> x;
		recieved += x;
	}

	recieved == expected ? cout << "YES\n" : cout << "NO\n";
	return 0;
}