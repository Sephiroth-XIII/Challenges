#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int K,N;
	cin >> K >> N;

	vector<string> lucky(K), pillow(N);

	for (int i = 0; i < K; ++i)
		cin >> lucky[i];

	for (int i = 0; i < N; ++i)
		cin >> pillow[i];

	for (int i = 0; i < N; ++i)
	{
		if(pillow[i].size() >= 47)
			cout << "Good\n";
		else
		{
			bool flag = true;
			for (int j = 0; j < K; ++j)
			{
				if(pillow[i].find(lucky[j]) != string::npos)
				{
					flag = false;
					cout << "Good\n";
					break;
				}
			}
			if(flag)
				cout << "Bad\n";
		}
	}
	return 0;
}