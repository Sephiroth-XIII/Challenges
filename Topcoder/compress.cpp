/*
Problem Statement
    	
Class Name: StringCompressor
Method Name: compress
Parameters: String
Returns: String

Implement a class StringCompressor, which contains a method compress.  The
method takes a String as a parameter and replaces all successively duplicated
letters in the String with a number that is the number of duplications followed
by the repeated character.  The method returns this resulting String.

The method signature is (be sure your method is public):
String compress(String toCompress)

TopCoder will ensure the following:
- toCompress is a String of at most 100 letters.  Each character is a lowercase
or capital letter ('a' - 'z' or 'A' - 'Z').

Note:
-This compressor is case sensative.  'A' is a different character than 'a'.
-Single letters (its neighbors are not duplicates of itself) are left alone.

Examples:
"AAAABBBBCDDDDDD" compresses to "4A4BC6D"
"SDFJaAAAAaaaass" compresses to "SDFJa4A4a2s"
"AAAAAAAAAAAf" compresses to "11Af"
 
Definition
    	
Class:	StringCompressor
Method:	compress
Parameters:	String
Returns:	String
Method signature:	String compress(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class StringCompressor
{
	public:
		string compress(string toCompress)
		{
			string compressed = "";
			vector<pair<char,int> > counter;
			for(int i = 0; i < toCompress.size(); i++)
			{
				if(i==0)
				{
					counter.push_back(make_pair(toCompress[i],1));
				}
				else if(i > 0)
				{
					if(toCompress[i] == toCompress[i-1])
						++counter[counter.size()-1].second;
					else
						counter.push_back(make_pair(toCompress[i],1));
				}
			}
			for(int i = 0; i < counter.size(); i++)
			{
				if(counter[i].second > 1)
				{
					ostringstream convert;
					convert << counter[i].second;
					compressed += convert.str();
				}
				compressed += counter[i].first;
			}
			return compressed;
		}
};

int main()
{
	StringCompressor *S = new StringCompressor;
	cout<<S->compress("AAAABBBBCDDDDDD")<<"\n";
	cout<<S->compress("SDFJaAAAAaaaass")<<"\n";
	cout<<S->compress("AAAAAAAAAAAf")<<"\n";
	cout<<S->compress("")<<"\n";
	cout<<S->compress("abcAbC")<<"\n";
	cout<<S->compress("aaAAdaddd")<<"\n";
	cout<<S->compress("abcdaacccc")<<"\n";
	cout<<S->compress("zxxxxxxxxxxxzz")<<"\n";
	return 0;
}