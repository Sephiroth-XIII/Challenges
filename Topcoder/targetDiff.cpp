/*
Problem Statement
    	
Class Name: DigitArrange
Method Name: targetDiff
Parameters: int
Returns: int

Implement a class DigitArrange which contains a method targetDiff.  The method
is passed two ints as parameters: a source and a target.  The method rearranges
the digits of the source to two distinct integers whose difference magnitude is
as close to without exceeding the target as possible.  The method returns the
magnitude of this difference.

Here is the method signature:
public int targetDiff(int source,int target);

The source is between 10 and 999999, inclusive.
The target is between 1 and 999999, inclusive.

Note:
-If it is impossible not to exceed the target, the method returns -1.
-Any 0s to the left of all non-zero digits in the source are not digits in
source.
-However, when arranging the digits of source, the first digit(s) of the
arranged value can be 0.
-One of the rearranged values may equal the source.

Examples:
-If the source is 981 and the target is 50, the two distinct values yielding
the difference's magnitude closest to the target are 918 and 891.  The
difference is 27 and the method returns 27.
-If the source is 450 and the target is 9, the two distinct values yielding the
difference's magnitude closest to the target are 045 and 054.  The method
returns the difference, 9.
-If the source is 100 and the target is 2, there is no way to arrange the
source's digits to get two distinct numbers whose difference is less than 2, so
the method returns -1.
 
Definition
    	
Class:	DigitArrange
Method:	targetDiff
Parameters:	int, int
Returns:	int
Method signature:	int targetDiff(int param0, int param1)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

class DigitArrange
{
	private:
		vector<int> l;

		void rearrange(int tr[], int digits, int val)
		{
			if(digits == 0)
				l.push_back(val);
			for (int i = 0; i < digits; ++i)
			{
				int e = val;
				int n[digits-1];
				for (int j = 0; j < i; ++j)
				{
					n[j] = tr[j];
				}
				for (int j = i+1; j < digits; ++j)
				{
					n[j-1] = tr[j];
				}
				e *= 10;
				e += tr[i];
				rearrange(n,digits-1, e);
			}
		}

	public:
		int targetDiff(int source, int target)
		{
			l.clear();
			int digits = 0;
			int y = source;
			while(y > 0)
			{
				digits++;
				y /= 10;
			}

			y = 0;
			int tr[digits];

			while(source > 0)
			{
				tr[y++] = source%10;
				source /= 10;
			}

			rearrange(tr,digits,0);

			int closest = target + 1;
			int mag = 0;

			for (int p = 0; p < l.size(); ++p)
			{
				for (int q = 0; q < l.size(); ++q)
				{
					int a, b;
					a = l[p];
					b = l[q];
					if(a < b)
						swap(a,b);
					if(a == b || a-b > target)
						continue;
					if(target - (a-b) < closest)
					{
						mag = a-b;
						closest = target-(a-b);
					}	
				}
			}
			if(closest == target+1)
				return -1;
			return mag;
		}
};

int main()
{
	DigitArrange *D = new DigitArrange;
	cout<<D->targetDiff(780, 20)<<"\n";
	cout<<D->targetDiff(30, 1000)<<"\n";
	cout<<D->targetDiff(279, 5)<<"\n";
	cout<<D->targetDiff(123621, 35)<<"\n";
	cout<<D->targetDiff(6892, 1)<<"\n";
	cout<<D->targetDiff(1752, 4000)<<"\n";
	cout<<D->targetDiff(123, 31)<<"\n";
	cout<<D->targetDiff(100, 2)<<"\n";
	cout<<D->targetDiff(11, 1000)<<"\n";
	cout<<D->targetDiff(900100, 990000)<<"\n";
	cout<<D->targetDiff(7001, 6999)<<"\n";
	cout<<D->targetDiff(199999, 999999)<<"\n";
	cout<<D->targetDiff(471, 2)<<"\n";
	return 0;
}