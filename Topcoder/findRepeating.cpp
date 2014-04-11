/*
Problem Statement
    	
Class Name: Repeating 
Method Name:  findRepeating 
Parameters: String
Return: String

Implement a class Repeating, which contains a method findRepeating.  The method
takes a String as a parameter.  The String represents a decimal truncated or
rounded to 10 decimal places and is of the form "0.<fract_part>" where
<fract_part> is 10 digits.  The method returns the shortest possible String
representing a simplified version of the same decimal with the repeating part
in parentheses (  ) and everything to the right of the repeating part truncated.

The method must find a group of one or more digits to the right of the decimal
point that is repeated throughout the remaining (to the group's right) of the
10 digits.  If the length of the group is ever longer than the remaining
digit(s), the group must start with the remaining digit(s) to be considered
repeating (See examples 3 & 4).  The first full occurrence of the repeating
group is put in parentheses, and everything after the parentheses is truncated.

If there is no possible repeating part, the input String should be returned
with no modifications.

If there are multiple repeating groups, return the representation that that
satisfies the following:
(1) Truncating everything after the repeating group results in the shortest
possible representation of the decimal.
(2) If there are multiple equally short representations, the correct
representation is the one with the largest part in parentheses. For example, if
the input String is "0.1234567811", both "0.(123456781)" and "0.12345678(1)"
have the same length. However, since the first choice has a larger part in
parentheses, the first is the correct representation.

Additional specifications:
(1) If the first occurrence of a group contains the 10th digit after the
decimal point, the group does not repeat and should not be considered a
possible repeating part.
(2) "0" should be treated no differently than any other digit.  It can repeat,
and trailing zeroes should not be truncated.

The method signature is:
String findRepeating(String decimal);

decimal is 12 characters and is of the form "0.<fract_part>" where <fract_part>
is 10 characters, each a number from 0 to 9, inclusive.

Examples:
(1) decimal="0.2500000000": return "0.25(0)"
(2) decimal="0.8333333333": return "0.8(3)"
(3) decimal="0.0323232323": return "0.0(32)" (Because the 10th digit is "3" and
the repeating part starts with "3")
(4) decimal="0.0714285714": return "0.0(714285)"
(5) decimal="0.1176470588": return "0.11764705(8)" ("8" is repeated through the
9th and 10th digit)
(6) decimal="0.1588235290": return "0.1588235290" (There is no possible
repetition, according to the rules above)
 
Definition
    	
Class:	Repeating
Method:	findRepeating
Parameters:	String
Returns:	String
Method signature:	String findRepeating(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>

using namespace std;

class Repeating
{
	public:
		string findRepeating(string decimal)
		{
			string best = decimal;
			int l = 100;
			for(int i = 9; i > 0; i--)
			{
				for(int j = 2; j<12-i ; j++)
				{
					bool ok = true;
					for(int k= j+i; k<12; k++)
					{
						ok &= (decimal[k] == decimal[j+(k-j)%i]);
					}
					if(ok)
					{
						string f = decimal.substr(0,j) + "(" + decimal.substr(j,i) + ")";
						if(f.size() < l)
						{
							best = f;
							l = f.size();
						}
					}
				}
			}
			return best;
		}
};

int main()
{
	Repeating *R = new Repeating;
	cout<<R->findRepeating("0.1378942220")<<"\n";
	cout<<R->findRepeating("0.0227890222")<<"\n";
	cout<<R->findRepeating("0.8178817881")<<"\n";
	cout<<R->findRepeating("0.8970897000")<<"\n";
	cout<<R->findRepeating("0.9811119898")<<"\n";
	return 0;
}