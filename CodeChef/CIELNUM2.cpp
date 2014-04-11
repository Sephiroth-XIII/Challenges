#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isLucky(string S)
{
	int c3=0,c5=0,c8=0;
	for (int i = 0; i < S.size(); ++i)
	{
		if(S[i] == '8')
			++c8;
		else if(S[i] == '5')
			++c5;
		else if(S[i] == '3')
			++c3;
		else
			return false;
	}
	return (c8 >= c5 && c5 >= c3 ? true : false);
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();

	int count = 0;
	for(;T--;)
	{
		string S;
		getline(cin,S);
		int i = 0,j = S.size();
		while(S[--j] < 48 || S[j] > 57)++i;
		S = S.substr(0,S.size()-i);
		istringstream iss(S);
		while(iss >> S);
		if(isLucky(S))++count;
	}
	cout << count << "\n";
	return 0;
}