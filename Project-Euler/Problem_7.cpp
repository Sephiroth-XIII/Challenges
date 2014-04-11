/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001st prime number?
*/

#include<iostream>

using namespace std;

#define TARGET 10001

int main()
{
	int i,j,m=0,primes[150000],flag=0;
	
	fill_n(primes,149999,1);
	primes[0]=0,primes[1]=0;
	
	for(i=2;i<150000;i++)
	{
		if(primes[i])
		{
			if(++m==TARGET)
			{
				cout<<i<<"\n";
				break;
			}
			for(j=i;j<150000;j+=i)
				primes[j]=0;
		}
	}	
	return 0;
}
			
