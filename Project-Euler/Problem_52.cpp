/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	for (int i = 1;; ++i)
	{
		int flag=0, count=0;
		bitset<10> N[6];
		for (int j = 1; j <=6 ; ++j)
		{
			int n=i*j;
			while(n)
			{
				N[j-1].set(n%10);
				n/=10;
			}
			if(j>1 && N[0]!=N[j-1])
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
	return 0;
}