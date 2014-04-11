/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include<iostream>

using namespace std;

int main()
{
	int NUM[400],CARRY[400],i,j,power=0,SUM;//NUM[400]:Assumming the result of 2^1000 is 400 digit long
	fill_n(NUM,399,0);
	fill_n(CARRY,399,0);
	NUM[399]=1;
	CARRY[399]=0;
	while(power<1000)
	{
		for(i=399;i>0;i--)
		{
			NUM[i]*=2;
			NUM[i]+=CARRY[i];
			CARRY[i-1]=NUM[i]/10;
			NUM[i]%=10;
		}
		++power;
	}
	SUM=0;
	for(i=0;i<400;i++)
	{
		SUM+=NUM[i];
		//THE BELOW TWO LINES WILL PRINT OUT THE RESULT OF 2^1000
		/*if(SUM>0)
			cout<<NUM[i];*/
	}
	cout<<SUM<<"\n";
	return 0;
}
