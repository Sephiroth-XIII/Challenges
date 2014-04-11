#include <iostream>
#include <string>
#include <map>

using namespace std;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b,a%b);
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string s;
		cin >> s;

		map<char,int> charCount;
		for (int i = 0; i < s.size(); ++i)
		{
			if(charCount.find(s[i]) == charCount.end())
				charCount[s[i]] = 0;
			charCount[s[i]]++;
		}
	}
}