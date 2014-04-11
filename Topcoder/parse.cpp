/*
Problem Statement
    	
Class Name: StringParser
Method Name: parse
Parameters: String
Returns: ArrayList

Implement a class StringParser, which contains a method parse.  The method
takes a String as a parameter.  The first(left-most) character of the String is
the delimiting character and the String is broken at each occurrence of the
delimiter and each occurrence of the delimiter is removed.  The method returns
an ArrayList of the pieces of non-zero length in the reverse order of their
occurrence.

For example, if the String is ".period.is.the..delimiter" the method returns
the ArrayList {"delimiter","the","is","period"}.

Here is the method signature:
public ArrayList parse(String toParse);

toParse is a String with length between 1 and 50 characters, inclusive.
toParse contains letters, digits, spaces, and simple punctuation
('.',',','?','!','-'). Note the pipe is not valid.

Note:
-If there are no pieces of non-zero length after breaking the String, the
method returns an empty instance of an ArrayList.
Examples:
-If toParse="AAthisAAAisAaAAtestAAA" the method returns {"test","a","is","this"}.

If you are not familiar with java.util.ArrayList, they are used to hold
objects, such as Integers and Strings. ArrayList.add(obj) will add obj to the
end of an Array List. ArrayList.get(n) will return the nth object.
ArrayList.remove(n) will remove the nth object and shift forward all objects
behind it. ArrayList.size() returns the number of objects in the ArrayList.
 
Definition
    	
Class:	StringParser
Method:	parse
Parameters:	String
Returns:	String[]
Method signature:	String[] parse(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class StringParser
{
	public:
		vector<string> parse(string toParse)
		{
			char ignore= toParse[0];
			vector<string> words;
			istringstream iss(toParse.substr(1));

			string str;
			while(getline(iss,str,ignore))
				if(str.size() != 0)
					words.push_back(str);

			reverse(words.begin(),words.end());

			return words; 
		}
};

int main()
{
	StringParser *S = new StringParser;
	vector<string> v;
	//v = S->parse(".period.is.the..delimeter");
	//v = S->parse("AAthisAAAisAaAAtestAAA");
	//v = S->parse(".");
	//v = S->parse(",This,is,,,a,test,");
	//v = S->parse("AHIAHOWAAREAYOU");
	//v = S->parse("zZZzZZ");
	v = S->parse("-1 HO 2?-3-A a");
	
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<"\""<<v[i]<<"\" ";
	}
	cout<<"\n";
	
	return 0;
}