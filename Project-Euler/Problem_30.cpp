/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 14 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include<iostream>
#include<cmath>

using namespace std;

int sdp5(int i);

int main()
{
	int i,sum=0;
	for(i=2;i<1000000;i++)
		if(i==sdp5(i))
			sum+=i;
	cout<<sum<<"\n";
	return 0;
}

int sdp5(int i)
{
	int x=0;
	while(i>0)
	{
		x+=pow(i%10,5);
		i/=10;
	}
	return x;
}
