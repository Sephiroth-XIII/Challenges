#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int XOR(int a, int b)
{
	return a^b;
}

int AND(int a, int b)
{
	return a&b;
}

int OR(int a, int b)
{
	return a|b;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,K,A;
		cin >> N >> K >> A;

		vector<int> answer(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> answer[i];
		}

		string opr;
		cin >> opr;

		auto op = XOR;

		if(opr == "AND")
			op = AND, K = min(K,1);
		else if(opr == "OR")
			op = OR, K = min(K,1);
		else
			K &= 1;

		while(K--)
			for (int i = 0; i < N; ++i)
				A = op(A, answer[i]);

		cout << A << "\n";
	}
	return 0;
}