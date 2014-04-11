/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,sq_sum=0,sum_sq=0;
	
	for(i=1;i<=100;i++)
	{	
		sum_sq+=pow(i,2);
		sq_sum+=i;
	}
	cout<<(int)(pow(sq_sum,2))-sum_sq<<"\n";
	return 0;
}
