/*
Problem Statement
    	
Class Name: Expressions
Method Name: evaluate
Parameters: String
Returns: int

Implement a class Expressions, which contains a method evaluate.  The method
takes a String as a parameter representing a mathematic expression and returns
the int that is is equivalent to the expression.

The expression contains non-negative integers and the operands *, +, - , /, and
parenthesis ( ). There is no white space in the expression.  The division (/)
is integer division (that is any remainder is truncated). Remember: Parentheses
are highest priority, then * and / are medium priority, then + and - are the
lowest priority.  When there are parentheses inside parentheses, the inner
parentheses are evaluated first.  When dealing with operands of equal priority,
evaluation occurs from left to right.

Here is the method signature.
public int evaluate(String expression);

expression is of length between 1 and 50.  It contains digits and the symbols
*, +, -, /, (, ) and represents a valid expression with no division by 0
(TopCoder will check this).

Example:
"6+2*(3*(1+1))-6/(2+3)" -> 17.
 
Definition
    	
Class:	Expressions
Method:	evaluate
Parameters:	String
Returns:	int
Method signature:	int evaluate(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Expressions
{
	private:

		string e;
		
		int p;

		int stringToInteger(string s)
		{
			istringstream iss(s);
			int n;
			iss >> n;
			return n;
		}

		int getP()
		{
			int istack[60];
			char opStack[60];
			int osize = 0;
			int ssize = 0;
			p++;

			istack[ssize++] = getN();

			while(e[p] != ')')
			{
				char op = e[p];
				p++;
				while(osize	> 0 && prec(opStack[osize-1]) <= prec(op))
				{
					int a = istack[--ssize];
					int b = istack[--ssize];
					char o = opStack[--osize];
					istack[ssize++] = dop(o,b,a);
				}
				opStack[osize++] = op;
				istack[ssize++] = getN();
			}

			while(osize > 0)
			{
				int a = istack[--ssize];
				int b = istack[--ssize];
				char o = opStack[--osize];
				istack[ssize++] = dop(o,b,a);
			}

			p++;
			return istack[0];
		}

		int getN()
		{
			if(e[p] == '(')
				return getP();

			string got = "";

			while(e[p] >= '0' && e[p] <= '9')
			{
				got += e[p];
				p++;
			}
			return stringToInteger(got);
		}

		int dop(char op, int a, int b)
		{
			switch(op)
			{
				case '+':
					return a+b;
				case '-':
					return a-b;
				case '*':
					return a*b;
				case '/':
					return a/b;
				default:
					return -1;
			}
		}

		int prec(char o)
		{
			switch(o)
			{
				case '+':
				case '-':
					return 2;
				case '*':
				case '/':
					return 1;
				default:
					return -1;
			}
		}

	public:

		int evaluate(string expression)
		{
			e = "(" + expression + ")";
			p = 0;
			return getP();
		}
};

int main()
{
	Expressions *E = new Expressions;
	cout<<E->evaluate("12+34")<<"\n";
	cout<<E->evaluate("4*8*3-4-4-3-1")<<"\n";
	cout<<E->evaluate("1/2/3/4/5+394-128/3*21-1-2+3-2/4")<<"\n";
	cout<<E->evaluate("99*(((5+6*23/5)*4+315)+(4-2)*4)/4+75/5")<<"\n";
	cout<<E->evaluate("((5-6)+(7-8))*(3-4-5-6-9)")<<"\n";
	cout<<E->evaluate("(8+(2*(5-2))/4)/2")<<"\n";
	cout<<E->evaluate("3*51-1-2/3/4/5+2")<<"\n";
	cout<<E->evaluate("10-2-2")<<"\n";
	cout<<E->evaluate("1/2/3/4/5/6+100-200-1-2-3-4+5/23+3-2*1-1-2-3")<<"\n";
	cout<<E->evaluate("6+2*(3*(1+1))-6/(2+3)")<<"\n";
	cout<<E->evaluate("3+2*6/4")<<"\n";
	cout<<E->evaluate("14*(3+(2+3)/4*2)/13")<<"\n";
	cout<<E->evaluate("3+6/4*2")<<"\n";
	cout<<E->evaluate("9-9/20-(1+2)")<<"\n";
	cout<<E->evaluate("2*(13-6*5/(1+1))")<<"\n";
	return 0;
}