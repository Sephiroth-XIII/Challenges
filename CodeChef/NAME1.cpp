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
		string M,F;
		cin >> M >> F;
		vector<int> parents(26,0);
		for (int i = 0; i < M.size(); ++i)
			++parents[M[i]-'a'];
		for (int i = 0; i < F.size(); ++i)
			++parents[F[i]-'a'];

		int N;
		cin >> N;
		vector<int> children(26,0);
		for(;N--;)
		{
			string C;
			cin >> C;
			for (int i = 0; i < C.size(); ++i)
				++children[C[i]-'a'];
		}

		bool flag = true;
		for (int i = 0; i < 26; ++i)
			if(children[i] > parents[i])
				flag = false;

		flag ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
} 