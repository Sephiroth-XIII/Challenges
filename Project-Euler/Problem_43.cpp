/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int a[10])
{
	int x;
	int b[7]={2,3,5,7,11,13,17};
	for (int j = 1; j <= 7; ++j)
	{
		x=0;
		for (int i = j; i <j+3 ; ++i)
		{
			x+=a[i];
			x*=10;
		}
		x/=10;
		if(x%b[j-1]!=0)return false;
	}
	return true;
}

int main()
{
	int a[10]={1,0,2,3,4,5,6,7,8,9};
	long x,sum=0;
	do
	{
		x=0;
		for (int i = 0; i < 10; ++i)
		{
			x+=a[i];
			x*=10;
		}
		x/=10;
		if(check(a))sum+=x;
	}while(next_permutation(a,a+10));
	cout<<sum<<"\n";
	return 0;
}