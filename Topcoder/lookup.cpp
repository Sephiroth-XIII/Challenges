/*
Problem Statement
    	
Class Name:  MagicSeries
Method Name: lookup
Parameters:  int
Returns:     int

Define a magic series of numbers to be the series of non-negative numbers
divisible by 2,3, or 5.
The magic series starts with 0, 2, 3, 4, 5, 6, 8, 9, 10, 12 . . .

Implement a class MagicSeries that contains a method lookup.  lookup takes an
index k as a parameter and returns an int that is the kth term of this magic
series of numbers.  0 is the 1st term of the series, 2 is the second, etc...

Here is the method signature:
public int lookup(int k);

k is greater than 0 and less than 1000000.

Examples:
If k=1, the method returns 0.
If k=2, the method returns 2. 
If k=20, the method returns 26.
 
Definition
    	
Class:	MagicSeries
Method:	lookup
Parameters:	int
Returns:	int
Method signature:	int lookup(int param0)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

class MagicSeries
{
	public:
		int lookup(int k)
		{
			int x;
			for(x = 0; k > 0; x++)
				if(x%2 == 0 || x%3 == 0 || x%5 == 0)k--;
			return x-1;
		}	
};

int main()
{
	MagicSeries *M = new MagicSeries;
	cout<<M->lookup(1)<<"\n";
	cout<<M->lookup(2)<<"\n";
	cout<<M->lookup(20)<<"\n";
	cout<<M->lookup(999999)<<"\n";
	cout<<M->lookup(10)<<"\n";
	cout<<M->lookup(15)<<"\n";
	return 0;
}