/*
The Fibonacci sequence is defined by the recurrence relation:
    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:
    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include<iostream>

using namespace std;

int main()
{
	int F1[1000],F2[1000],Fib[1000],Carry[1000],count=2,i;
	fill_n(F1,1000,0);
	fill_n(F2,1000,0);
	fill_n(Fib,1000,0);
	fill_n(Carry,1000,0);
	F1[999]=F2[999]=1;
	Carry[999]=0;
	while(Fib[0]==0)
	{
		for(i=999;i>0;i--)
		{
			Fib[i]=F1[i]+F2[i]+Carry[i];
			Carry[i-1]=Fib[i]/10;
			Fib[i]%=10;
		}
		Fib[0]+=Carry[0];
		for(i=0;i<1000;i++)
		{
			F1[i]=F2[i];
			F2[i]=Fib[i];
		}
		++count;
	}
	cout<<count<<"\n";
	return 0;
}
