/*
Problem Statement
    	
Class name:  Punnet
Method name: computeProbability
Parameters:  String, String, String
Returns:     double

Phenotypes are traits and are determined by genotypes which are represented by
a pair of alleles - one from the mother and one from the father.  Each allele
is represented by a letter and can be either dominant or recessive where the
capital letter indicates the trait is dominant, and the lowercase indicates a
recessive trait.  If one or more of the pair of alleles is dominant, then the
expressed phenotype is the dominant trait. If two recessive alleles are
present, then the recessive trait is the expressed phenotype.

When two organisms breed, the offspring organism randomly gets one of the two
alleles of each of the mother's genotypes and one of the two alleles of each of
the father's genotypes.  For each genotype, these two alleles constitute the
pair of alleles of the offspring's genotype, and thus determine which phenotype
will be expressed in the offspring.

For example, assume that peas can be either yellow or green.  The allele for
the color of the peas can be either "A" or "a", with "A" representing the
dominant trait yellow peas and "a" representing the recessive trait green peas.
If an organism's alleles for pea color are one of "AA", "Aa", or "aA", then
the peas are yellow, otherwise, they are green ("aa").  Assume that the mother
has green peas (alleles "aa") and that the father has yellow peas (alleles
"Aa").  The Punnet square shows the four offspring possible:

Mom\Dad |    aA   |
--------+----+----+
        | aa | aA |
   aa   +----+----+
        | aa | aA |
--------+----+----+
Because the child can get the first small a from mom and the small a from dad or
the second small a from mom and the small a from dad or
the first small a from mom and the big A from dad or
the second small a from mom and the big A from dad.

So there is 2/4=50% chance the offspring will have green peas and a 2/4=50%
chance the offspring will have yellow peas.

Implement a class Punnet, which contains a method computeProbability.  The
method computes the probability that the offspring from two given parents will
have a certain set of phenotypes.  Input parameters will be (String mom, String
dad, String child) where mom and dad are up to 30 characters long indicating
their respective alleles for up to 15 phenotypes (one for each of the first 15
letters of the alphabet in alphabetical order), and child is up to 15
characters long indicating the desired trait for each phenotype (one character
in the string for each phenotype in the parents, in order).  Output will be a
double that holds the theoretical probability that the child will occur during
any given mating.

The method signature is:
double computeProbability(String mom,String dad,String child);

TopCoder will check the validity of mom, dad, and child.

Notes:
-mom and dad are of even length since the alleles come in pairs
-The first allele pair is for the A/a phenotype, the second for the B/b
phenotype, and so on.
-The total probability is the product of the probability of each of the
considered probabilities.
-If a space occurs in the child, that indicates that we do not care about that
specific phenotype, and that its probability should not be considered.
-If the child is all spaces, we don't care about anything, and the method
should return 1.0.

In the example above, if we wanted green peas, then:
mom = "aa"
dad = "aA"
child = "a"
and 0.5 would be returned.

Another example:
mom   = "aABBCcDd"
dad   = "AabbCCDd"
child = "A Cd"
For A/a:  The child may be AA, aA, Aa, or aa, so there is a 3/4 chance the
child will express the dominant A phenotype.
For B/b:  We do not care (space)
For C/c:  The child may be CC, CC, Cc, or Cc, so there is a 4/4 chance the
child will express the dominant C phenotype.
For D/d:  The child may be DD, Dd, dD, or dd, so there is a 1/4 chance the
child will express the recessive d phenotype.
Therefore .75*1*.25=0.1875 is returned.
 
Definition
    	
Class:	Punnet
Method:	computeProbability
Parameters:	String, String, String
Returns:	double
Method signature:	double computeProbability(String param0, String param1, String param2)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Punnet
{
	public:
		double computeProbability(string mom, string dad, string child)
		{
			double probability[2][15];
			for (int i = 0; i < mom.size()/2 ; ++i)
			{
				bool first = isupper(mom[2*i]);
				bool sec = isupper(mom[2*i+1]);
				if(first && sec)
					probability[0][i] = 0;
				else if(first || sec)
					probability[0][i] = 0.5;
				else
					probability[0][i] = 1.0;

				first = isupper(dad[2*i]);
				sec = isupper(dad[2*i+1]);
				if(first && sec)
					probability[1][i] = 0;
				else if(first || sec)
					probability[1][i] = 0.5;
				else
					probability[1][i] = 1.0;
			}
			
			double d = 1.0;

			for (int i = 0; i < child.size(); ++i)
			{
				if(child[i] == ' ')
					continue;
				else if(isupper(child[i]))
					d *= (1.0 - probability[0][i] * probability[1][i]);
				else
					d *= (probability[0][i] * probability[1][i]);
			}

			return d;
		}
};

int main()
{
	Punnet *P = new Punnet;
	cout<<P->computeProbability("aA", "Aa", "A")<<"\n";
	cout<<P->computeProbability("aa", "aa", "A")<<"\n";
	cout<<P->computeProbability("AabbCcDdEe", "aaBbccDDEE", "ABCDE")<<"\n";
	cout<<P->computeProbability("AA", "AA", "a")<<"\n";
	cout<<P->computeProbability("", "", "")<<"\n";
	cout<<P->computeProbability("AA", "AA", "a")<<"\n";
	cout<<P->computeProbability("Aa", "Aa", "a")<<"\n";
	cout<<P->computeProbability("AaBb", "AABB", " ")<<"\n";
	cout<<P->computeProbability("AaBBCcDdEe", "AABbccddEe", " bcd ")<<"\n";
	cout<<P->computeProbability("AaBbCCDdEeffgGHHiI", "aabbccddeeFfGghHII", "abCDEFG ")<<"\n";
	cout<<P->computeProbability("AabBcCdDEe", "Aabbccddee", "ABCDE")<<"\n";
	return 0;
}
