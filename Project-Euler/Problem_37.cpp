/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
#include<iostream>
#include<cmath>

using namespace std;

int is_prime[1000000];

void generate_primes();
int right_trun(int i);
int left_trun(int i);
int main()
{
	int N,count=0,flag,X,Y,M,O,sum=0;
	generate_primes();
	for(N=10;N<1000000;N++)
	{
		if(is_prime[N])
		{
			M=N;
			O=N;
			flag=0;
			while((X=right_trun(M))!=0 && (Y=left_trun(O))!=0)
			{
				if(is_prime[X]==0 || is_prime[Y]==0)
				{
					flag=1;
					break;
				}
				M=X;
				O=Y;
			}
			if(flag==0)
			{
				sum+=N;
				++count;
				if(count==11)break;
			}
		}
	}
	cout<<sum<<"\n";
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

int right_trun(int i)
{
	return i/10;
}

int left_trun(int i)
{
	int j=i,size=0;
	while((j/=10)!=0)++size;
	int X=pow(10,size);
	return i%X;
}
