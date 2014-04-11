/*
Problem Statement
    	
Implement a class PrimeNumbers that contains a method pairwisePrimes.  The
method inputs an int (num) and returns the number of ways the number can be
written as the sum of three distinct integers that are pairwise relatively
prime; that is no pair of the three integers has a common factor greater than 1.

Note:

- num is greater than 0 and less than or equal to 40.
- One of the three distinct integer can be 1; Numbers are Pairwise Relatively
Prime if they share no factor GREATER than 1.

Method Signature:

public int pairwisePrimes( int );

Examples:

For num=8:  8 can be written as 1+2+5 and 1+3+4 and the method should return 2.
For num=18, the method should return 14
 
Definition
    	
Class:	PrimeNumbers
Method:	pairwisePrimes
Parameters:	int
Returns:	int
Method signature:	int pairwisePrimes(int param0)
(be sure your method is public)
*/

#include <iostream>

using namespace std;

class PrimeNumbers
{
	private:
		int GCD(int a, int b)
		{
			if(b == 0)
				return a;
			else
				return GCD(b,a%b);
		}
	public:
		int pairwisePrimes(int num)
		{
			int count = 0;
			for (int i = 1; i <= num; ++i)
			{
				for (int j = i+1; j <= num ; ++j)
				{
					int k = num - i - j;
					if(k>j && GCD(i,j) == 1 && GCD(i,k) == 1 && GCD(j,k) == 1)
						++count;
				}
			}
			return count;
		}
};

int main()
{
	PrimeNumbers *p = new PrimeNumbers();

	cout<<p->pairwisePrimes(13)<<"\n";
	cout<<p->pairwisePrimes(38)<<"\n";
	cout<<p->pairwisePrimes(27)<<"\n";
	cout<<p->pairwisePrimes(32)<<"\n";
	cout<<p->pairwisePrimes(12)<<"\n";

	return 0;
}