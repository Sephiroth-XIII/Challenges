/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital
Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include<iostream>
#include<set>

using namespace std;

int is_pandigital(int i,int j,int k);
int main()
{
	int i,j,k,sum=0;
	set<int> bucket;
	
	for(i=100;i<2000;i++)
	{
		for(j=1;j<50;j++)
		{
			k=i*j;
			if(is_pandigital(i,j,k))
			{
				bucket.insert(k);
			}
		}
	}
	
	set<int> ::iterator p;
	
	for(p=bucket.begin();p!=bucket.end();p++)
	{
		sum+=*p;
	}
	cout<<sum<<"\n";
	return 0;
}

int is_pandigital(int i,int j,int k)
{
	set<int> num;
	int count=0;
	while(i!=0)
	{
		num.insert(i%10);
		if(i%10==0)return 0;
		i/=10;
		++count;
	}
	while(j!=0)
	{
		num.insert(j%10);
		if(j%10==0)return 0;
		j/=10;
		++count;
	}	
	while(k!=0)
	{
		num.insert(k%10);
		if(k%10==0)return 0;
		k/=10;
		++count;
	}
	if(num.size()==9 && count==9)return 1;
	return 0; 
}
