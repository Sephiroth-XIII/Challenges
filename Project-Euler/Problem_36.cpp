/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
#include<iostream>

using namespace std;

int is_pal_10(int i);
int is_pal_2(int i);
unsigned long long generate_bin(int i);
int main()
{
	int N,count=0;
	for(N=1;N<1000000;N++)
	{
		if(is_pal_10(N) && is_pal_2(N))
		{
			count+=N;
		}
	}
	cout<<count<<"\n";
	return 0;
}

int is_pal_10(int i)
{
	int j=i,N=0;
	while(j!=0)
	{
		N*=10;
		N+=(j%10);
		j/=10;
	}
	if(N==i)return 1;
	return 0;
}

int is_pal_2(int i)
{	
	if(i%2==0)return 0;
	unsigned long long bin=generate_bin(i),bin_rev=0,j=bin;
	while(j!=0)
	{
		bin_rev*=10;
		bin_rev+=(j%10);
		j/=10;
	}
	if(bin==bin_rev)return 1;
	return 0;
}

unsigned long long generate_bin(int i)
{
	unsigned long long j=i,bin=0;
	while(j!=0)
	{
		bin*=10;
		bin+=j%2;
		j/=2;
	}
	return bin;
}

