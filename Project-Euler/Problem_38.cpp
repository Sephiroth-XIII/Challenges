/*
Take the number 192 and multiply it by each of 1, 2, and 3:
192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string itoa(long i);
string generate_pan(long i);
bool check_pan(string i);

int main()
{
	long max=0;
	for (long i = 1; i < 9999; ++i)
	{
		string s;
		s=generate_pan(i);
		if(check_pan(s))
		{
			long n;
			istringstream(s)>>n;
			if(n>max)max=n;
		}
	}
	cout<<max<<"\n";
	return 0;
}

string itoa(long i)
{
	stringstream ss;
	string s;
	ss<<i;
	ss>>s;
	return s;	
}

string generate_pan(long i)
{
	string o=itoa(i);
	long j=2;
	while(o.size()<9)
	{
		o+=itoa(i*j);
		j++;
	}
	return o;
}

bool check_pan(string s)
{
	int num[10];
	fill_n(num,10,0);
	for (int i = 0; i < s.size(); ++i)
	{
		++num[s[i]-'0'];
	}
	if(num[0])return false;
	for (int i = 1; i < 10; ++i)
	{
		if(num[i]!=1)return false;
	}
	return true;
}