/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include<iostream>
#include<cmath>

using namespace std;

#define MAX 20

int main()
{
	int i,j,result=1,primes[MAX+1];
	
	fill_n(primes,MAX,1);
	primes[0]=0,primes[1]=0;
	for(i=2;i<=sqrt(MAX);i++)
	{
		if(primes[i])
		{
			for(j=i*i;j<=MAX;j+=i)
				primes[j]=0;
		}
	}
	for(i=2;i<=MAX;i++)
	{
		if(primes[i])
		{
			for(j=1;j<MAX;j++)
			{
				if(pow(i,j)<=MAX)
					result*=i;
				else
					break;
			}
		}
	}
	cout<<result<<"\n";
	return 0;
}
			
			
			
