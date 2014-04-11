/*
Problem Statement
    	
Class name: ModEncoder
Method name: encoder
Parameters: String
Returns: String

Implement a class ModEncoder, which contains a method encoder.  encoder accepts
a String to encode and outputs the String encoded using the algorithm described
below.

The encoding algorithm:  
First, append the minimum number of spaces required to the input string so the
string's length is a multiple of 5. Replace all spaces with tildes(~). Write
out the message in rows of 5 characters, putting each successive row below the
previous row. The encoded message starts with the message read one column at a
time, moving top to bottom down the columns and left to right across the
columns.  Finally, append a dollar sign to the encoded message to indicate the
end of the message.

For example, suppose the message is "THIS CODED MESSAGE".  It is 18 characters
long so two spaces are added at the end to make the message 20 characters long.
The rows of five characters are:
T H I S ~
C O D E D
~ M E S S
A G E ~ ~
The characters are sent one column at a time from left to right as shown below,
and a dollar sign is appended.
The encoded message is: TC~AHOMGIDEESES~~DS~$

The method signature is:
public String encoder(String input);

input will contain only letters, numbers, and spaces and will be at least 1
character and at most 100 characters.

Note:
-The encoding should remember the case.

Examples:
-The message "TopCoder is cool" is encoded to "Tdsloe~~prc~C~o~oio~$".

 
Definition
    	
Class:	ModEncoder
Method:	encoder
Parameters:	String
Returns:	String
Method signature:	String encoder(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>

using namespace std;

class ModEncoder
{
	public:
		string encoder(string input)
		{
			for(int i = input.length(); i%5 != 0; i++)
				input += " ";
			for(int i = 0; i<input.length(); i++)
				if(input[i] == ' ')
					input[i] = '~';
			string output = "";
			int rows = input.length()/5;
			for(int i = 0; i<input.length(); i++)
				output += input[(i/rows)+(i%rows)*5];
			return output+"$";
		}	
};

int main()
{
	ModEncoder *M = new ModEncoder;
	cout<<M->encoder("THIS CODED MESSAGE")<<"\n";
	cout<<M->encoder("HoW1 aRe You")<<"\n";
	cout<<M->encoder("12345")<<"\n";
	cout<<M->encoder("Exact2rows")<<"\n";
	cout<<M->encoder("Let us try a extraordinarily long message0123456789")<<"\n";
	cout<<M->encoder("1")<<"\n";
	return 0;
}