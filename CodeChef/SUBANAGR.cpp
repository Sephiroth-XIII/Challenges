#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<vector<int> > A(T);

	for(int i = 0; i < T; ++i)
	{
		string S;
		cin >> S;

		vector<int> C(26,0);
		for (int j = 0; j < S.size(); ++j)
			++C[S[j]-'a'];

		A[i] = C;
	}

	bool flag = true;
	for (int i = 0; i < 26; ++i)
	{
		int MIN = 101;
		for (int j = 0; j < T; ++j)
		{
			if(A[j][i] < MIN)
				MIN = A[j][i];
		}
		if(MIN > 0)
			flag = false;
		while(MIN--)
			cout << char('a'+i);
	}
	if(flag)
		cout<<"no such string";
	cout << "\n";

	return 0;
}