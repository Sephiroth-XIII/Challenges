#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>

using namespace std;

bitset<1000005> p;

int main()
{
	vector<int> primes;
	vector<int> primesSqr;
	vector<int> primesCube;
	
	p.set();
	p.reset(0);
	p.reset(1);

	for (int i = 2; i <= 1000000; ++i)
	{
		if(p[i])
		{
			primes.push_back(i);
			if(i <= sqrt(1000000))
				primesSqr.push_back(i*i);
			if(i <= pow(1000000,1.0/3.0))
				primesCube.push_back(i*i*i);
			if(i <= sqrt(1000000))
			for (int j = i*i; j <= 1000000 ; j+=i)
			{
				p.reset(j);
			}
		}
	}

	int N;
	while(cin >> N && N != 0)
	{
		bool flag = false;
		for (int i = 0; i < primesCube.size(); ++i)
		{
			for (int j = 0; j < primesSqr.size(); ++j)
			{
				if(binary_search(primes.begin(),primes.end(),N-primesCube[i]-primesSqr[j]))
				{
					cout << N-primesCube[i]-primesSqr[j] << " " << sqrt(primesSqr[j]) << " " << pow(primesCube[i],1.0/3.0) << "\n";
					flag = true;
					break;
				}
			}
			if(flag==true)
				break;
		}
		if(!flag)
			cout << "0 0 0\n";
	}
	return 0;
}