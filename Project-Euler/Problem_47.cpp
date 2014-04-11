/*
The first two consecutive numbers to have two distinct prime factors are:
14 = 2 × 7
15 = 3 × 5
The first three consecutive numbers to have three distinct prime factors are:
644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.
Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/
#include <iostream>
#include <cmath>
using namespace std;

int PRIME[200001];
void gen_prime()
{
	fill_n(PRIME,200001,0);
	PRIME[0]=-1;
	PRIME[1]=-1;
	for (int i = 2; 2*i <= 200000; ++i)
	{
		if(PRIME[i]==0)
		{
			for (int j = 2*i; j <=200000 ; j+=i)
			{
				++PRIME[j];
			}
		}
	}
}

int main()
{
	gen_prime();
	int i;
	for (i = 0; i <=200000-4 ; ++i)
	{
		if(PRIME[i]==4 && PRIME[i+1]==4 && PRIME[i+2]==4 && PRIME[i+3]==4)break;
	}
	cout<<i<<"\n";
	return 0;
}