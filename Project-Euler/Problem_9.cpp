/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int a,b,c,flag=0;
	
	for(a=500;a>1;a--)
	{	
		for(b=a;b>1;b--)
		{
			for(c=b;c>1;c--)
			{
				if(a+b+c==1000)
				{
					if(pow(a,2)==pow(b,2)+pow(c,2))
					{
						cout<<a*b*c<<"\n";
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			break;
	}
	return 0;
}
	

