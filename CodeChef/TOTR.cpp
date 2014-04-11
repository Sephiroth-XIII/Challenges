#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	string S;

	cin >> T >> S;

	int A[26];
	for (int i = 0; i < S.size(); ++i)
		A[i] = S[i] - ('a'+i);

	for(;T--;)
	{
		string X;
		cin >> X;

		for (int i = 0; i < X.size(); ++i)
			if(X[i] == '_')
				cout << " ";
			else if(X[i] == '.' || X[i] == ',' || X[i] == '!' || X[i] == '?')
				cout << X[i];
			else if(X[i] >= 'a' && X[i] <= 'z')
				cout << char(X[i]+A[X[i]-'a']);
			else
				cout << char(X[i]+A[X[i]-'A']);
		cout<<"\n";
	}
	return 0;
}