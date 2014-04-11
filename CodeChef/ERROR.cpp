#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string S;
		cin >> S;

		S.find("010") != string::npos || S.find("101") != string::npos ? cout << "Good\n" : cout << "Bad\n";
	}
	return 0;
}