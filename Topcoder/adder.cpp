/*
Problem Statement
    	
Class Name: Bases
Method Name: adder
Parameters: String,String,int
Returns: String

Implement a class Bases, which contains a method adder.  The method takes two
Strings as parameters representing numbers in a certain number base and an int
that is that base.  The method returns the sum of the numbers, also in the same
base.

Adding numbers in bases other than 10 is similar to adding numbers in base 10.
Start at the least significant digit, add, and carry...  There is a carry when
the sum is greater than or equal to the number base.

The base will be at most 16.
For base 16, the digits in order are:
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
For any base b less than 16, the digits are the first b digits in the list above.

For example, add 613.56 and 104.4 in base 7:

  11
 104.40
 613.56
-------
1021.26
(When adding the 4 and the 5 to the right of the decimal, the sum is 2 more
than the base, so there is a carry (1) and the sum minus the base (2) is
written below...)

For example. add 1D.8 and 2.A in base 16:

11
1D.8
02.A
----
20.2

When returning the sum, all leading 0s are truncated, unless the result is 0.
If the result is 0, the method returns "0".
If the fractional part is 0, the point and all 0s to its right are truncated.
If the fractional part is non-zero, all trailing 0s are truncated.

Here is the method signature (be sure your method is public):
String adder(String arg1, String arg2, int base)

TopCoder will ensure the following:
base is between 2 and 16, inclusive.
arg1 and arg2 have length at least 1 and at most 50. 
arg1 and arg2 correctly represent non-negative numbers in the specified base
and contain only the characters '0' - '9' and 'A' - 'F' and '.'.

NOTES:
arg1 and arg2 may or may not have a '.', fractional part, or integer part.
The left most digit of arg1 and arg2 is the most significant digit.  The right
most digit is least significant.

Examples:
*If arg1 = 102.4, arg2 = 63.23, and base=10, the method returns 165.63
*If arg1 = 1D.EE, arg2 = D11.A12, and base=15, the method returns D30.A02
*If arg1 = .4, arg2 = .4, and base=8, the method returns 1
 
Definition
    	
Class:	Bases
Method:	adder
Parameters:	String, String, int
Returns:	String
Method signature:	String adder(String param0, String param1, int param2)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class Bases
{
	private:
		vector<int> integerize(string s)
		{
			vector<int> b(102);
			int i = s.find('.');
			if(i == -1)
				i = s.size();
			int j = 51-i;

			for(int k = 0; k < s.size(); k++)
				if(s[k] != '.')
					b[j++] = (s[k] >= 'A' ? 10+s[k] - 'A' : s[k]-'0');

			return b;
		}

		vector<int> decimalBaseAddition(vector<int> x, vector<int> y, int base)
		{
			int c = 0;
			vector<int> b(102);
			for (int i = 101; i >= 0; --i)
			{
				int n = x[i]+y[i]+c;
				b[i] = n % base;
				c = n / base;
			}
			return b;
		}

		string decimalToString(vector<int> a)
		{
			string c = "";
			int i,j;
			for (i = 0; i < 51 && a[i]==0; ++i);
			for(;i<51;i++)
				c += (char)(a[i]>9 ? 'A'+a[i]-10:'0'+a[i]);
			for(j=102 ; --j>51 && a[j]==0;);
			if(j>51 || (j==51 && a[j]!=0))
			{
				c += '.';
				for(;i<=j;i++)
					c += (char)(a[i]>9 ? 'A'+a[i]-10:'0'+a[i]);
			}
			return c.length()==0?"0":c;
		}

	public:
		string adder(string arg1, string arg2, int base)
		{
			vector<int> x = integerize(arg1);
			vector<int> y = integerize(arg2);
			vector<int> z = decimalBaseAddition(x,y,base);
			return decimalToString(z);
		}
};

int main()
{
	Bases *B = new Bases;
	cout<<B->adder("1001.111","11010.00011",2)<<"\n";
	cout<<B->adder("321.123","1.1",5)<<"\n";
	cout<<B->adder("123456.066","001234.166",7)<<"\n";
	cout<<B->adder("A.92","D.EE",15)<<"\n";
	cout<<B->adder("3",".2",4)<<"\n";
	return 0;
}