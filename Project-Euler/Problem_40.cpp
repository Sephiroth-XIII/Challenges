/*
An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the value of the following expression.
d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string itoa(long i)
{
	stringstream ss;
	string s;
	ss<<i;
	ss>>s;
	return s;	
}

int main()
{
	int res=1,count=0,i=1;
	while(count<=1000000)
	{
		string n=itoa(i);
		for (int j = 0; j < n.size(); ++j)
		{
			count++;
			if(count==1 || count==10 || count==100 || count==1000 || count==10000 || count==100000 || count==1000000)
			{
				res*=(n[j]-'0');
			}
		}
		i++;
	}
	cout<<res<<"\n";
	return 0;
}