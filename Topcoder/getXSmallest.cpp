/*
Problem Statement
    	
Implement a class Fraction, which contains a method getXSmallest.  The method
is passed two integers: an index and a maximum denominator. The program should
find all fractions of the form a / b where b is less than or equal to the
maximum denominator and a / b is less than 1 and then return the index-th
smallest of these fractions.  The method should return the fraction as a double
value, rounded to 3 decimal points (use the supplied formatDouble function).

Note:

- If index value is greater than the number of fractions that are less than 1,
the method should return 1.
- Fractions should not be simplified.  1/2 and 2/4 are two unique fractions,
despite their equal double values
- The class and method must be declared as public
- The index must be between 1 and 70, inclusive.  The max denominator must be
between 2 and 12, inclusive. (TopCoder will check these constraints, you need
not.)

The method signature is :

public double getXSmallest(int, int);

Example:

For example, if index = 3 and max denominator = 4, all the fractions of the
form a / b are 1/4, 1/3, 1/2, 2/4, 2/3, 3/4, and the method should return the
third smallest, as a double: 0.5.
 
Definition
    	
Class:	Fraction
Method:	getXSmallest
Parameters:	int, int
Returns:	double
Method signature:	double getXSmallest(int param0, int param1)
(be sure your method is public)
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Fraction
{
	public:
		double getXSmallest(int index, int maxDenominator)
		{
			double list[10000];
			fill_n(list,10000,1.0);

			int k = 0;
			for (int i = 1; i <= maxDenominator; ++i)
			{
				for (int j = 1; j < i; ++j)
				{
					list[k++] = ((double)j*1.0)/((double)i*1.0);
				}
			}

			sort(list,list+10000);
			cout.precision(3);
			cout.setf( std::ios::fixed, std:: ios::floatfield );
			return list[index-1];
		}
};

int main()
{
	Fraction *f = new Fraction();
	cout<<f->getXSmallest(1,2)<<"\n";
	cout<<f->getXSmallest(63,8)<<"\n";
	cout<<f->getXSmallest(40,12)<<"\n";
	cout<<f->getXSmallest(53,11)<<"\n";
	cout<<f->getXSmallest(14,7)<<"\n";
}