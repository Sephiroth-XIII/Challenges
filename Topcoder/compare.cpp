/*
Problem Statement
    	
Class Name: CommonChar
Method Name: compare
parameters:  String, String
returns: int

Create a class CommonChar containing the method compare. This method will take
two Strings as inputs and return the number of characters in the second String
that are contained in the first string, in a one-to-one relationship.  That is,
if a character is repeated in the second string, it must be repeated in the
first string to count more than once.

Here is the method signature:
public int compare(String input1, String input2);

BOth Strings will have fewer than 100 characters.

Note:
-The method is case sensitive.  A is a different character than a.

Examples:
("java", "abava") -> 3  (two of the (a)s and the (v))
("TopCoder", "code guru") -> 4
("foobar", "sing") -> 0 
 
Definition
    	
Class:	CommonChar
Method:	compare
Parameters:	String, String
Returns:	int
Method signature:	int compare(String param0, String param1)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CommonChar
{
	public:
		int compare(string input1, string input2)
		{
			int charCount[256];
			fill_n(charCount,256,0);

			for(int i=0;i<input1.size();i++)
			{
				++charCount[input1[i]];
			}

			int comChar = 0;

			for(int i=0;i<input2.size();i++)
			{
				if(charCount[input2[i]] > 0)
				{
					++comChar;
					--charCount[input2[i]];
				}
			}

			return comChar;
		}	
};

int main()
{
	CommonChar *C = new CommonChar;
	
	cout<<C->compare("java","abava")<<"\n";
	cout<<C->compare("TopCoder","code guru")<<"\n";
	cout<<C->compare("foobar","sing")<<"\n";

	cout<<C->compare("","")<<"\n";
	cout<<C->compare("aAa","aAaA")<<"\n";
	cout<<C->compare("Hi1 how are you", "I am 1good")<<"\n";
	cout<<C->compare(".,~~abcABC","~~~efgaaABB")<<"\n";
	cout<<C->compare("abc3", "abc3")<<"\n";



	return 0;
}