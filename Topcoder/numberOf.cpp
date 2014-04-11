/*
Problem Statement
    	
Class Name:  WellOrdered
Method Name: numberOf
Parameters:  int,int
Returns:     int

Implement a class WellOrdered, which contains a method numberOf.  The method
takes two ints as parameters: the number of digits, d, and the number base, b.
The method returns an int (base-10) that is the number of positive well ordered
integers with d digits in the base-b number system.

A well ordered integer is an integer in which the digits strictly increase from
left(most significant) to right(least significant).  For example 145 is a well
ordered integer.  442 and 445 are not.

In base 16, the digits from smallest to greatest are:
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
In any base, b, less than or equal to 16, the digits are the first b of those
above.

Therefore, in base 12, 79B is a well ordered integer of three digits.  In base
16, the number 8CDE is a well ordered integer of four digits.  E6 is not a well
ordered integer in base 15 (nor in base-16 for that matter...).

The method signature is:
int numberOf(int digits, int base);
Be sure your method is public.

digit and base satisfy:
0 < digit < 5
1 < base < 17

Note:
Any 1 non-zero digit number is well ordered.
Numbers with leading zeroes are not valid.  For example, 012 is not a well
ordered number with three digits.

Examples:
-In base 5, the well ordered numbers with 3 digits are:
 123
 124
 134
 234
 So if digit=3 and base=5, the method should return 4.
 
Definition
    	
Class:	WellOrdered
Method:	numberOf
Parameters:	int, int
Returns:	int
Method signature:	int numberOf(int param0, int param1)
(be sure your method is public)
*/

#include <iostream>

using namespace std;

class WellOrdered
{
	private:
		int counter(int digits, int base, int currentDigit)
		{
			int rez = 0;
			if(digits == 0)
				return 1;
			if(digits == 1)
				return base - currentDigit;
			for (int i = currentDigit; i < base; ++i)
				rez += counter(digits - 1, base, i+1);
			return rez;
		}

	public:
		int numberOf(int digits, int base)
		{
			if(digits == 1)
				return base - 1;
			else
				return counter(digits, base, 1);
		}	
};

int main()
{
	WellOrdered *W = new WellOrdered;
	cout<<W->numberOf(4,16)<<"\n";
	cout<<W->numberOf(3,13)<<"\n";
	cout<<W->numberOf(4,3)<<"\n";
	cout<<W->numberOf(3,15)<<"\n";
	cout<<W->numberOf(1,2)<<"\n";
	cout<<W->numberOf(4,10)<<"\n";
	cout<<W->numberOf(4,9)<<"\n";
	cout<<W->numberOf(3,4)<<"\n";
	cout<<W->numberOf(4,15)<<"\n";
	cout<<W->numberOf(4,2)<<"\n";
	cout<<W->numberOf(2,3)<<"\n";
	cout<<W->numberOf(2,2)<<"\n";
	cout<<W->numberOf(1,2)<<"\n";
	cout<<W->numberOf(1,10)<<"\n";
	return 0;
}