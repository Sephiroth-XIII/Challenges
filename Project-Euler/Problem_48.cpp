/*
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/
#include <iostream>
#include <cmath>
using namespace std;

unsigned long power(int n)
{
	unsigned long a=1;
	for (int i = 0; i < n; ++i)
	{
		a=(a*n)%(unsigned long)pow(10,10);
	}
	return a;
}

int main()
{
	unsigned long sum=0;
	for (int i = 1; i <=1000 ; ++i)
	{
		sum=(sum+power(i))%(unsigned long)pow(10,10);
	}
	cout<<sum<<"\n";
	return 0;
}