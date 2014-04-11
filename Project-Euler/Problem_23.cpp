/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{   
	int candidates[28123];
	fill_n(candidates,28123,0);
	candidates[0]=0;
	vector<int> abundant;
	set<int> non_abundant;
	int SUM=0,i,j,sum,x;
	
	for(i=1;i<28123;i++)
	{
		if(candidates[i]==0)
		{
			sum=0;
			for(j=1;j<=i/2;j++)
				if(i%j==0)
					sum+=j;
			if(sum>i)
				for(j=i;j<28123;j+=i)
					candidates[j]=1;					
		}
	}
	
	for(i=0;i<28123;i++)
		if(candidates[i])
			abundant.push_back(i);
	
	for(i=1;i<28123;i++)
		non_abundant.insert(i);
		
	for(i=0;i<abundant.size();i++)
		for(j=i;j<abundant.size();j++)
			non_abundant.erase(abundant[i]+abundant[j]);
			
	set<int>::iterator p;
	for(p=non_abundant.begin();p!=non_abundant.end();p++)
		SUM+=*p;		
	cout<<SUM<<"\n";
	return 0;
}
