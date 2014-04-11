/*
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include<iostream>

using namespace std;

#define RANGE 1000000

long long Collatz(long long n,long long count);
long long C_list[RANGE];

int main()
{
	long long i,max=0,max_no=0;
	fill_n(C_list,(RANGE-1),0);
	for(i=1;i<RANGE;i++)
	{
		C_list[i]=Collatz(i,1);
		if(C_list[i]>max)
		{
			max=C_list[i];
			max_no=i;
		}
	}
	cout<<max_no<<"\n";
	return 0;
}

long long Collatz(long long n,long long count)
{
	if(n==1)
	{
		return count;
	}
	else if(n<RANGE && C_list[n]!=0)
	{
		return (count+C_list[n]-1);
	}
	else if(n%2&1)
	{
		return Collatz((3*n)+1,++count);
	}
	else
	{
		return Collatz(n/2,++count);
	}
}
