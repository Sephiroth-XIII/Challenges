/*
Problem Statement
    	
Implement a class Finances, which contains a function timeLeft.  timeLeft is
passed three int values.  The initial value of the bank account is
initialValue.  Interest is compounded monthly at a rate of interest percent.
Every month monthly dollars is taken out from the account (immediately after
the Interest has been added).  timeLeft must return an int that is the number
of months the account can support the full monthly withdrawal.  If the account
will last longer than 1200 months, the function should return 1200.

The method signature is:
int timeLeft(int initialValue, int interest, int monthly).

NOTE: initialValue and monthly are greater than or equal to 0 and less than or
equal to 100,000.  interest is greater than or equal to 0 and less than or
equal to 1000.

Examples:
(100, 0, 100) -> 1
(200, 1, 300) -> 0
(3453, 8, 200) -> 1200
 
Definition
    	
Class:	Finances
Method:	timeLeft
Parameters:	int, int, int
Returns:	int
Method signature:	int timeLeft(int param0, int param1, int param2)
(be sure your method is public)
*/

#include <iostream>

using namespace std;

class Finances
{
	public:
		int timeLeft(int initialValue, int interest, int monthly)
		{
			double initVal = initialValue*1.0;
			double rate = interest*0.01;
			for (int i = 0; i < 1200; ++i)
			{
				initVal += (initVal*rate);
				initVal -= monthly;
				if(initVal < 0)
					return i;
			}
			return 1200;
		}
};

int main()
{
	Finances *f = new Finances();
	cout<<f->timeLeft(100,20,100)<<"\n";
	cout<<f->timeLeft(50,10,10)<<"\n";
	cout<<f->timeLeft(2000,10,2300)<<"\n";
	cout<<f->timeLeft(100,14,1)<<"\n";
	cout<<f->timeLeft(1,50,1)<<"\n";
	return 0;
}