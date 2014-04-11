/*
n! means n × (n − 1) × ... × 3 × 2 × 1
For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!
*/

#include<iostream>

using namespace std;

int main()
{
	int NUM[200],CARRY[200],i,j,fact=2,SUM;//NUM[200]:Assumming the result of 100! is 200 digit long
	fill_n(NUM,199,0);
	fill_n(CARRY,199,0);
	NUM[199]=1;
	CARRY[199]=0;
	while(fact<=100)
	{
		for(i=199;i>0;i--)
		{
			NUM[i]*=fact;
			NUM[i]+=CARRY[i];
			CARRY[i-1]=NUM[i]/10;
			NUM[i]%=10;
		}
		++fact;
	}
	SUM=0;
	for(i=0;i<200;i++)
	{
		SUM+=NUM[i];
		//THE BELOW TWO LINES WILL PRINT OUT THE RESULT OF 100!
		/*if(SUM>0)
			cout<<NUM[i];*/
	}
	//cout<<"\n";
	cout<<SUM<<"\n";
	return 0;
}
