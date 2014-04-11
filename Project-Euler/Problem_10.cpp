/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include<iostream>
#include<cmath>

using namespace std;

#define MAX 2000000
int main()
{
	int i,j,primes[MAX+1];
	unsigned long long SUM=0;
	
	fill_n(primes,MAX,1);
	primes[0]=0,primes[1]=0;
	for(i=2;i<sqrt(MAX);i++)
	{
		if(primes[i])
		{	
			for(j=i*i;j<MAX;j+=i)
				primes[j]=0;
		}
	}
	for(i=2;i<MAX;i++)
		if(primes[i])
			SUM+=i;
	cout<<SUM<<"\n";
	return 0;
}
				
