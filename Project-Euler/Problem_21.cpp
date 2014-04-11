/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/

#include<iostream>

using namespace std;

int main()
{
	int i,j,SUM,SUM1,COUNT=0,candidates[10000]={0};	
	candidates[0]=4;
	for(i=2;i<10000;i++)
	{
		if(candidates[i]==0)
		{
			SUM=0;
			for(j=1;j<=i/2;j++)
			{
				if(i%j==0)
					SUM+=j;
			}
			candidates[i]=SUM;
		}
		
		if(candidates[i]<10000 && candidates[i]!=i)
		{
			SUM1=0;
			for(j=1;j<=candidates[i]/2;j++)
			{
				if(SUM%j==0)
					SUM1+=j;
			}
			candidates[j]=SUM1;
			if(i==SUM1)
				COUNT+=i;
		}
	}	
	cout<<COUNT<<"\n";
	return 0;
}
