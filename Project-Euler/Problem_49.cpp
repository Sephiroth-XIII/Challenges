/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
What 12-digit number do you form by concatenating the three terms in this sequence?
*/
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bitset<10000> PRIME;
void gen_prime()
{
	PRIME.set();
	PRIME.reset(0);
	PRIME.reset(1);
	for (int i = 2; i*i <=9999 ; ++i)
	{
		if(PRIME[i])
		{
			for (int j = i*i; j <=9999 ; j+=i)
			{
				PRIME.reset(j);
			}
		}
	}
	return;
}

int CHECK(int i)
{
	int w,x=i,y=0,z=0;
	vector<int> D;
	set<int> S;

	while(i)
	{
		D.push_back(i%10);
		i/=10;
	}
	reverse(D.begin(),D.end());
	do
	{
		S.insert(D[0]*1000+D[1]*100+D[2]*10+D[3]);
	}while (next_permutation(D.begin(),D.end()));
	for(set<int>::iterator j=S.begin();j!=S.end();j++)
	{
		if(!PRIME[*j])continue;
		if(*j>x)
		{
			y=*j;
			z=2*y-x;
			if(PRIME[z] && S.find(z)!=S.end())
			{
				cout<<x<<y<<z<<"\n";
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	gen_prime();
	vector<int> P;
	for (int i = 1000; i <=9999; ++i)
	{
		if(PRIME[i])P.push_back(i);
	}
	for (int i = 0; i <P.size() ; ++i)
	{
		if(P[i]!=1487 && CHECK(P[i]))break;
	}
	return 0;
}