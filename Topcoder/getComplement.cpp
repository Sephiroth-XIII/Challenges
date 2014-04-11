/*
Problem Statement
    	
Class Name:  DNA
Method Name: getComplement
Arg Types:   String
Return Type: String

Implement a class DNA, which contains a method getComplement. getComplement
takes a String representing a strand of DNA and returns the complement of that
strand, as a String.

DNA is composed of the following four bases: adenine, guanine, thymine, and
cytosine.  Two strands of DNA are considered complements of each other if all
of the following conditions are met:
     -   they are of equal length
-   for each adenine in the first strand, a thymine is located in the
exact same position of the second strand
-   for each thymine in the first strand, an adenine is located in the
exact same position of the second strand
-   for each guanine in the first strand, a cytosine is located in the
exact same position of the second strand
-   for each cytosine in the first strand, a guanine is located in the
exact same position of the second strand

In both the input String and return String, let A stand for adenine, T for
thymine, C for cytosine and G for guanine and let each character in the String
represent a position in the DNA strand.

Here is the method signature:
String getComplement(String strStrand);
Be sure your method is public.

* strStrand has length 1 to 50, inclusive.
* strStrand contains only the characters 'A', 'T', 'C', and 'G'.

Examples:
* If the input is "GAAACT", the method should return "CTTTGA"
* If the input is "ACCAAAAGCTGCAGTATGA", the method should return
"TGGTTTTCGACGTCATACT"
* If the input is "TAGGTCTCACTTAGCTTTCGTCCCTATAGTATATAGCTCCCAACCATCCA", the
method should return "ATCCAGAGTGAATCGAAAGCAGGGATATCATATATCGAGGGTTGGTAGGT"
 
Definition
    	
Class:	DNA
Method:	getComplement
Parameters:	String
Returns:	String
Method signature:	String getComplement(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>

using namespace std;

class DNA
{
	public:
		string getComplement(string strStrand)
		{
			string complementStrand = "";
			for(int i = 0; i < strStrand.size(); i++)
			{
				if(strStrand[i] == 'A')
					complementStrand += 'T';
				else if(strStrand[i] == 'T')
					complementStrand += 'A';
				else if(strStrand[i] == 'C')
					complementStrand += 'G';
				else if(strStrand[i] == 'G')
					complementStrand += 'C';
			}
			return complementStrand;
		}	
};

int main()
{
	DNA *D = new DNA;
	cout<<D->getComplement("GAAACT")<<"\n";
	cout<<D->getComplement("ACCAAAAGCTGCAGTATGA")<<"\n";
	cout<<D->getComplement("TAGGTCTCACTTAGCTTTCGTCCCTATAGTATATAGCTCCCAACCATCCA")<<"\n";
	
	cout<<D->getComplement("ATCG")<<"\n";
	cout<<D->getComplement("TTTTTTTTA")<<"\n";
	cout<<D->getComplement("CCAA")<<"\n";
	cout<<D->getComplement("TGTG")<<"\n";
	cout<<D->getComplement("ATC")<<"\n";
	cout<<D->getComplement("AT")<<"\n";
	return 0;
}