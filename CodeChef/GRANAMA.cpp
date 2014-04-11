#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string A,B;
		cin >> A >> B;

		vector<int> a(26,0), b(26,0);
		bitset<26> a1,b1;

		for (int i = 0; i < A.size(); ++i)
			++a[A[i]-'a'],a1.set(A[i]-'a');
		for (int i = 0; i < B.size(); ++i)
			++b[B[i]-'a'],b1.set(B[i]-'a');
		
		a1 == b1 && a != b ? cout << "NO\n" : cout << "YES\n";
	}
	return 0;
}