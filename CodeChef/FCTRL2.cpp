#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string str(int n)
{
	ostringstream oss;
	oss << n;
	return oss.str();
}

int main()
{
	int T;
	cin>>T;

	string FACT[101];
	FACT[0] = "1";
	for (int i = 1; i <= 100 ; ++i)
	{
		string b = FACT[i-1];
		string n="";
		int s = b.size(),x=0,rem=0,car=0;
		for(int j = s-1 ;j >=0;j--)
		{
			x = (b[j]-'0')*i+car;
			car = 0;
			rem = x%10;
			car = x/10;
			n = char(rem+'0')+n;
			if(j == 0 && car!=0) n = str(car) + n;
		}
		FACT[i] = n;
	}

	for(;T--;)
	{
		int N;
		cin >> N;
		cout << FACT[N] <<"\n";
	}
	return 0;
}