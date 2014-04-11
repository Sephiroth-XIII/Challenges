/*
Problem Statement
    	
Class Name:  Combiner
Method Name: combine
Parameters:  String,String
Returns:     String

Implement a class Combiner, which contains a method combine.  The method takes
two Strings as parameters and combines them, alternating letters, starting with
the first letter of the first String, followed by the first letter of the
second String, then second letter of first String, etc.  The remaining letters
of the longer String are then appended to the end of the combination String and
this combination String is returned.

Here is the method signature:
public String combine(String s1,String s2);

s1 and s2 are Strings of length between 1 and 50 letters, inclusive.

Examples:
If s1="Tpo" and s2="oCder" the method returns "TopCoder".
If s1="aa" and s2="bb" the method returns "abab".
 
Definition
    	
Class:	Combiner
Method:	combine
Parameters:	String, String
Returns:	String
Method signature:	String combine(String param0, String param1)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Combiner
{
	public:
		string combine(string s1, string s2)
		{
			string output = "";

			int minSize = min(s1.size(),s2.size());
			
			for(int i = 0; i < minSize; i++)
				output = output + s1[i] + s2[i];

			output = output + s1.substr(minSize) + s2.substr(minSize);

			return output;
		}	
};

int main()
{
	Combiner *C = new Combiner;
	cout << C->combine("Tpo","oCder")<<"\n";
	cout << C->combine("Firstislonger", "b")<<"\n";
	cout << C->combine("seCond", "issomewhatlongeR")<<"\n";
	cout << C->combine("samexx", "length")<<"\n";
	cout << C->combine("a", "b")<<"\n";
	cout << C->combine("longsame", "longsame")<<"\n";
	cout << C->combine("a", "bc")<<"\n";
	cout << C->combine("asdfgbasdf", "brrac")<<"\n";
	cout << C->combine("abc", "de")<<"\n";
}