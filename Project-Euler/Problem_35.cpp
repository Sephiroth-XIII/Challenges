/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
*/
#include<iostream>
#include<cmath>

using namespace std;

int is_prime[1000000];

void generate_primes();
int circular_shift(int i);
int main()
{
	int N,count=0,flag,X,M;
	generate_primes();
	for(N=1;N<1000000;N++)
	{
		if(is_prime[N])
		{
			M=N;
			flag=0;
			while((X=circular_shift(M))!=N)
			{
				if(is_prime[X]==0)
				{
					flag=1;
					break;
				}
				M=X;
			}
			if(flag==0)++count;
		}
	}
	cout<<count<<"\n";
	return 0;
}

void generate_primes()
{
	int i,j;
	fill_n(is_prime,1000000,1);
	is_prime[0]=0;
	is_prime[1]=0;
	for(i=2;i<=sqrt(1000000);i++)
		if(is_prime[i])
			for(j=i*i;j<1000000;j+=i)
				is_prime[j]=0;
}

int circular_shift(int i)
{
	int r=i%10,size=0,j=i;
	while((j/=10)!=0)size++;
	i=(pow(10,size)*r)+(i/10);
	return i;
}
