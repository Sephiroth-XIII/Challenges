#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		long long N,K;
		cin >> N >> K;
		K == 0 ? cout << "0 " << N <<"\n" : cout << N/K << " " << N%K <<"\n";
	}
	return 0;
}