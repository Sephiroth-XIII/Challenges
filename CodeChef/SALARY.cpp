#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		int total = 0, MIN = 10001;
		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			total += x;
			if(x < MIN) MIN = x;
		}
		cout << total - N*MIN << "\n";
	}
	return 0;
}