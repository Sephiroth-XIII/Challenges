#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;

		vector<string> direction(N),places(N);
		for (int i = 0; i < N; ++i)
		{
			string adj;
			cin >> direction[i] >> adj;
			getline(cin, places[i]);
		}

		for (int i = N-1; i >= 0 ; --i)
		{
			if(i == N-1)
				cout << "Begin on" << places[i] <<"\n";
			else
				direction[i+1] == "Right" ? cout << "Left on" << places[i] << "\n" : cout << "Right on" << places[i] << "\n";
		}
		cout <<"\n";
	}
	return 0;
}