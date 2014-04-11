#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		long long N,x;
		cin >> N;
		for(int i = 0 ; i < N ; i++)
			cin >> x;
		cout << (N * (N - 1))/2 <<"\n";
	}
	return 0;
}