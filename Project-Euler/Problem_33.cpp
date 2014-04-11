/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
#include<iostream>

using namespace std;

float StrDiv(int N,int D);
int gcd(int N,int D);
int main()
{
	int N,D,DT=1,NT=1;
	for(N=11;N<100;N++)
	{
		for(D=11;D<=100;D++)
		{
			if(N%10!=0 && D%10!=0 && N!=D && N/D<1)
			{
				if(float(N)/D==StrDiv(N,D))
				{
					DT*=(D/gcd(N,D));
					NT*=(N/gcd(N,D));
				}
			}
		}
	}
	cout<<DT/NT<<"\n";
	return 0;
}

float StrDiv(int N,int D)
{
	int Na,Nb,Da,Db;
	Nb=N%10;
	Na=N/10;
	Db=D%10;
	Da=D/10;
	if(Na==Da)
		return float(Nb)/Db;
	if(Nb==Da)
		return float(Na)/Db;
	if(Na==Db)
		return float(Nb)/Da;
	if(Nb==Db)
		return float(Na)/Da;
	return -1;
}

int gcd(int N,int D)
{
	if(D%N==0)
		return N;
	gcd(D,D%N);
}
