/*
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
Let us list the factors of the first seven triangle numbers:
     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.
What is the value of the first triangle number to have over five hundred divisors?
*/

#include<iostream>
#include<cmath>

using namespace std;

#define TARGET 500

int factors(int triangle);

int main()
{
	int j=TARGET,i=j+1,triangle=0;
	
	triangle=(j*(j+1))/2;
	
	while((factors(triangle))<TARGET)
	{
		triangle+=i++;
	}
	cout<<triangle<<"\n";
	return 0;
}

int factors(int triangle)
{
	int i,f=0;
	for(i=1;i<=sqrt(triangle);i++)
		if(triangle%i==0)
			++f;
	f*=2;
	if(floor(sqrt((float)triangle)) == sqrt((float)triangle))
		--f;
	return f;
}
