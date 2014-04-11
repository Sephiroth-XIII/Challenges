/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12
It turns out that the conjecture was false.
What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

bitset<10001> PRIME;
void gen_prime()
{
	PRIME.set();
	PRIME.reset(0);
	PRIME.reset(1);
	for (int i = 2; i*i <= 10000; ++i)
	{
		if(PRIME[i])
		{
			for (int j = i*i; j <=10000 ; j+=i)
			{
				PRIME.reset(j);
			}
		}
	}
}

int main()
{
	gen_prime();
	int flag;
	for (int i = 3; i < 10001; i+=2)
	{
		if(PRIME[i]==0)
		{
			flag=0;
			for (int j = 1; 2*j*j < i ; ++j)
			{
				if(PRIME[i-2*j*j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}