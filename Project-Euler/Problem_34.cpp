/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
#include<iostream>

using namespace std;

int main()
{
	int fact[10]={1,1,2,6,24,120,720,5040,40320,362880},i,j,N,sum=0;
	for(i=11;i<50000;i++)
	{
		N=0;
		j=i;
		while(j>0 && N<=i)
		{
			N+=fact[j%10];
			j/=10;
		}
		if(N==i)
			sum+=i;
	}
	cout<<sum<<"\n";
	return 0;
}
