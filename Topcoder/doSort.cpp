/*
Problem Statement
    	
Implement a class LetterSort, which contains a method doSort.  doSort takes a
String as a parameter and sorts the characters in the string in order of their
first appearance in the string.  For example CABCACCB sorts to CCCCAABB.  The
method doSort should return the sorted String.

The method signature is:
public String doSort(String input);

input is a string of at least 1 character and at most 50 characters.  The
characters are letters or numbers.

Note:
-The sort is case sensitive.  "A" is a different character than "a".

Examples:
If input="TopCoder", the method returns "ToopCder"
If input="HiHowAreYou", the method returns "HHioowAreYu"
 
Definition
    	
Class:	LetterSort
Method:	doSort
Parameters:	String
Returns:	String
Method signature:	String doSort(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LetterSort
{
	public:
		string doSort(string input)
		{
			vector<pair<pair<int,int>,char> > C;

			for (int i = 0; i < 256; ++i)
			{
				C.push_back(make_pair(make_pair(300,0),char(i)));
			}

			for (int i = 0; i < input.size(); ++i)
			{
				if(C[input[i]].first.first == 300)
				{
					C[input[i]].first.first = i;
					C[input[i]].first.second = 0;
				}
				++C[input[i]].first.second;
			}

			string output = "";
			sort(C.begin(),C.end());
			for (int i = 0; i < 256 ; ++i)
			{
				while(C[i].first.second--)
					output += C[i].second;
			}
			return output;
		}
};

int main()
{
	LetterSort *L = new LetterSort;
	cout<<L->doSort("TopCoder")<<"\n";
	cout<<L->doSort("ThisIsATest")<<"\n";
	cout<<L->doSort("abcdeABCDE")<<"\n";
	cout<<L->doSort("SlipperySam")<<"\n";
	cout<<L->doSort("AbCdEEdCbA")<<"\n";
	cout<<L->doSort("nachonachoma1n21")<<"\n";
	return 0;
}