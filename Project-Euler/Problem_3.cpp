/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const long long NUM=600851475143;

int main()
{	
	long long i,j,result,primes[(long long)(sqrt(NUM))+1],m=1;
	//SIEVE OF ERATOSTHENES FOR PRIMES UPTO SQRT(NUM)
	fill_n(primes,sqrt(NUM),1);
	primes[0]=0;
	primes[1]=0;
	for(i=2;i<sqrt(sqrt(NUM));i++)
	{
		if(primes[i])
		{
			for(j=i*i;j<=sqrt(NUM);j+=i)
			{
				primes[j]=0;
			}
		}
	}
	//WE START THE LOOP IN REVERSE SO ONLY 1 SUCCESSFUL COMPARISON IS NEEDED WHICH IS THE ANSWER
	for(i=sqrt(NUM);i>2;i--)
	{
		if(primes[i]==1 && NUM%i==0)
		{
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
