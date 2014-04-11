/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

bitset<1000000> PRIME;
void gen_prime()
{
	PRIME.set();
	PRIME.reset(0);
	PRIME.reset(1);
	for (int i = 2; i*i <=999999 ; ++i)
	{
		if(PRIME[i])
		{
			for (int j = i*i; j <=999999 ; j+=i)
			{
				PRIME.reset(j);
			}
		}
	}
	return;
}

int main()
{
	gen_prime();
	vector<int> N;
	int optimus=0;
	for (int i = 0; i <=999999; ++i)
	{
		if(PRIME[i])N.push_back(i);
	}
	vector<int> N1(N);
	for (int i = 1; i < N1.size(); ++i)
	{
		for (int j = 0; j <N1.size()-i ; ++j)
		{
			if(N1[j]==-1)break;
			N1[j]+=N[j+i];
			if(N1[j]>=1000000)
			{
				N1[j]=-1;
				break;
			}
			if(N1[j]<1000000 && PRIME[N1[j]])optimus=N1[j];
		}
	}
	cout<<optimus<<"\n";
	return 0;
}