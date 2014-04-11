/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
using namespace std;
bitset<10000000> PRIMES;
void gen_prime()
{
	PRIMES.set();
	PRIMES.reset(0);
	PRIMES.reset(1);
	for (int i = 2; i*i < 10000000; ++i)
	{
		if(PRIMES[i])
		{
			for (int j = i*i; j < 10000000 ; j+=i)
			{
				PRIMES.reset(j);
			}
		}
	}
	return;
}
int CHECK(int n)
{
	int min=9,x=n,j,count=0;
	vector<int> index;
	while(x)
	{
		if(x%10<min)min=x%10;
		x/=10;
	}
	x=n;
	j=0;
	while(x)
	{
		if(x%10==min)index.push_back(j);
		x/=10;
		++j;
	}
	for (int i = 1; i <=9-min ; ++i)
	{
		x=n;
		for (int j = 0; j < index.size(); ++j)
		{
			x+=(pow(10,index[j])*i);
		}
		if(PRIMES[x])
		{
			++count;
		}	
	}
	return count;
}
/*void PRINT_FAMILY(int n)
{
	int min=9,x=n,j,count=0;
	vector<int> index;
	while(x)
	{
		if(x%10<min)min=x%10;
		x/=10;
	}
	x=n;
	j=0;
	while(x)
	{
		if(x%10==min)index.push_back(j);
		x/=10;
		++j;
	}
	for (int i = 1; i <=9-min ; ++i)
	{
		x=n;
		for (int j = 0; j < index.size(); ++j)
		{
			x+=(pow(10,index[j])*i);
		}
		if(PRIMES[x])
		{
			cout<<x<<"\n";
		}	
	}
	return;
}*/
int main()
{
	gen_prime();
	for (int i = 2; i <10000000 ; ++i)
	{
		if(PRIMES[i])
		{
			if(CHECK(i)==7)
			{
				cout<<i<<"\n";
				//Uncommentinig the line below and function above will print all the primes in the 8-prime family
				//PRINT_FAMILY(i);
				break;
			}
		}
	}
	return 0;
}