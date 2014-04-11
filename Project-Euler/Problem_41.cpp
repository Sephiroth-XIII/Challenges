/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool is_prime(long a)
{
	for (long i = 2; i <= sqrt(a); ++i)
	{
		if(a%i==0)return false;
	}
	return true;
}
int main()
{
	for (int j = 0; j <9 ; ++j)
	{
		int a[9]={9,8,7,6,5,4,3,2,1};
		long x,flag=0;
		do
		{
			x=0;
			for (int i = j; i < 9; ++i)
			{
				x+=a[i];
				x*=10;
			}
			x/=10;
			if(is_prime(x))
			{
				flag=1;
				cout<<x<<"\n";
				break;
			}
		}while(prev_permutation(a+j,a+9));
		if(flag==1)break;
	}
	return 0;
}