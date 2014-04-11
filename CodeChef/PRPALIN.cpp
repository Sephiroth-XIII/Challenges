#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

bool isPalindrome(int n)
{
	int n1 = n , n2 = 0;
	while(n1 != 0)
	{
		n2 *= 10;
		n2 += n1%10;
		n1 /= 10;
	}
	return n2 == n;
}

int main()
{
	vector<int> primePalindromes;

	bitset<1100001> primes;
	primes.set();
	primes.reset(0);
	primes.reset(1);
	for (int i = 2; i <= sqrt(1100000) ; ++i)
	{
		if(primes[i])
		{
			for (int j = i*i; j <= 1100000 ; j+=i)
			{
				primes.reset(j);
			}
		}
	}
	for (int i = 0; i <= 1100000; ++i)
	{
		if(primes[i] && isPalindrome(i))
		{
			primePalindromes.push_back(i);
		}
	}

	int N;
	cin>>N;

	for (int i = 0; i < primePalindromes.size(); ++i)
	{
		if(primePalindromes[i] >= N)
		{
			cout<<primePalindromes[i]<<"\n";
			break;
		}
	}
	return 0;
}