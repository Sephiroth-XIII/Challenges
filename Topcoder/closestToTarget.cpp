/*
Problem Statement
    	
Class Name: DigitArith
Method Name: closestToTarget
Parameters: int, int
Returns: int

Implement a class DigitArith, which contains a method closestToTarget.  The
method takes 2 ints as parameters: a source and a target.  The method performs
3 digit arithmetic operations (defined below) successively on the source and
returns the closest possible result to the target.

Digit Arithmetic Operations:
1. Addition - any digit in the operand can be added to the operand.  Defined
when the result is less than 10,000.
2. Subtraction - any digit in the operand can be subtracted from the operand.
Defined when the result is non-negative.
3. Multiplication - any digit in the operand can be multiplied by the operand.
Defined when the result is less than 10,000.
4. Division - any digit in the operand can divide the operand.  The floor of
the result is taken (Integer Division). Defined when the digit is non-zero.

Note:
-The operations are performed on the result of the previous operation.  ex: for
the second operation, a digit is chosen from the result of the first, not the
source.
-No intermediate results can be negative.
-The digits are always non-negative.

The method signature is:
int closestToTarget(int source, int target);

source and target are non-negative integers less than 1,000.

Example:
-If the source is 12 and the target is 85, the three operations that yeild the
result closest to the target are
 12, take the (2) digit, and multiply: 12*2=24 
 24, take the (4), and multply: 24*4=96 
 96, take the (9), and subtract: 96-9=87
 And the method should return 87.
-If the source is 54 and the target is 13,
 54/4=13 -> 13+1=14 -> 14-1=13.
 And the method should return 13.
 
Definition
    	
Class:	DigitArith
Method:	closestToTarget
Parameters:	int, int
Returns:	int
Method signature:	int closestToTarget(int param0, int param1)
(be sure your method is public)
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DigitArith
{
	private:
		int best;
		int goal, retv;
		void go(int here, int level)
		{
			if(here < 0 || here >= 10000) return;
			if(level == 3)
			{
				if(abs(here - goal) < best)
				{
					best = abs(here - goal);
					retv = here;
				}
				return;
			}

			int t = here;
			while(t > 0)
			{
				go(here + t%10, level + 1);
				go(here - t%10, level + 1);
				go(here * (t%10), level + 1);
				if(t%10 != 0)
					go(here / (t%10), level + 1);
				t /= 10;
			}
		}

	public:
		int closestToTarget(int source, int target)
		{
			best = 10000;
			goal = target;
			go(source, 0);
			return retv;	
		}	
};

int main()
{
	DigitArith *D = new DigitArith;
	cout<<D->closestToTarget(0,0)<<"\n";
	cout<<D->closestToTarget(100,0)<<"\n";
	cout<<D->closestToTarget(4,50)<<"\n";
	cout<<D->closestToTarget(96,14)<<"\n";
	cout<<D->closestToTarget(999,300)<<"\n";
	return 0;
}