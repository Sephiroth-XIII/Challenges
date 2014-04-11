/*
Problem Statement
    	
Class Name: Derivatives
Method Name: calcDerivative
Parameters: String,int,int
Returns: int

Implement a class Derivatives which contains a method calcDerivative.  The
method takes a String representing a polynomial, and two ints, k and x.  The
method returns the kth derivative of the polynomial evaluated at x.

The first derivative of any term of a polynomial is:
1st derivative of (a*x^n) = (a*n*x^(n-1)).

The first derivative of any polynomial is the sum of the first derivatives of
the polynomial's terms.
The kth derivative of a polynomial is the 1st derivative of the (k-1)th
derivative of the polynomial.
The 0th derivative of a polynomial is the polynomial itself.

The String will be of the form:
"a1*x^n1+a2*x^n2+...."
There are no spaces.
All the a's are non-negative integers less than 20
All the n's are unique non-negative integers less than 10.
The String is at most 50 characters and at least 5 characters.

Here is the method signature:
public int calcDerivative(String poly,int k,int x);

poly is of the correct form.
k is an integer between 0 and 10, inclusive.
x is an integer between -10 and 10, inclusive.

Examples:
*If poly="3*x^3+2*x^1+2*x^0", k=1, and x=1:
The first derivative is: 3*3*x^(3-1)+2*1*x^(1-1)+0*2*x^(0-1)=9*x^2+2*x^0.
The first derivative evaluated at x=1 is: 9*1^2+2*1^0=11
So the method returns 11.

*If poly="2*x^5+3*x^2", k=2, and x=-2,
The first derivative is: 5*2*x^(5-1)+3*2*x^(2-1)=10*x^4+6*x^1.
The second derivative is: 10*4*x^(4-1)+6*1*x^(1-1)=40*x^3+6*x^0.
The second derivative evaluated at x=-2 is 40*(-2)^3+6*(-2)^0=-314.
So the method returns -314.
 
Definition
    	
Class:	Derivatives
Method:	calcDerivative
Parameters:	String, int, int
Returns:	long
Method signature:	long calcDerivative(String param0, int param1, int param2)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Derivatives
{
	private:
		long stringToLong(string s)
		{
			istringstream iss(s);
			long n;
			iss>>n;
			return n;
		}

	public:
		long calcDerivative(string poly, int k, int x)
		{
			vector<long> multiple, power;
			istringstream iss(poly);
			string s;
			while(getline(iss,s,'*'))
			{
				multiple.push_back(stringToLong(s));
				getline(iss,s,'^');
				getline(iss,s,'+');
				power.push_back(stringToLong(s));
			}

			for (int i = 0; i < k; ++i)
			{
				for (int j = 0; j < multiple.size(); ++j)
				{
					multiple[j] *= power[j];
					power[j]--; 
				}
			}

			long answer = 0;
			
			for (int i = 0; i < multiple.size(); ++i)
			{
				answer += multiple[i]*pow(x,power[i]);
			}
			
			return answer;
		}
};

int main()
{
	Derivatives *D = new Derivatives;
	cout<< D->calcDerivative("3*x^4",2,1)<<"\n";
	cout<< D->calcDerivative("2*x^1+3*x^4+6*x^6",0,-2)<<"\n";
	cout<< D->calcDerivative("9*x^9+8*x^2+3*x^1",3,4)<<"\n";
	cout<< D->calcDerivative("3*x^2+4*x^4",8,-8)<<"\n";
	cout<< D->calcDerivative("5*x^6+3*x^3",3,-4)<<"\n";
	cout<< D->calcDerivative("3*x^9+10*x^8",0,-10)<<"\n";
	cout<< D->calcDerivative("20*x^2",0,2)<<"\n";
	cout<< D->calcDerivative("19*x^9+18*x^8+17*x^7",5,9)<<"\n";
	cout<< D->calcDerivative("3*x^9+10*x^8",0,-10)<<"\n";
	cout<< D->calcDerivative("1*x^1",2,2)<<"\n";

	return 0;
}