/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include<iostream>

using namespace std;

int main()
{
	int i=1,limit=1001*1001,count=0,incr=2,sum=0;
	while(i<=limit)
	{
		sum+=i;
		i+=incr;
		++count;
		if(count%4==0)incr+=2;
	}
	cout<<sum<<"\n";
	return 0;
}
