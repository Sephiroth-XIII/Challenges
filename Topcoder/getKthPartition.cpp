/*
Problem Statement
    	
Class Name: Partitions
Method Name: getKthPartition
Parameters: int,int
Returns: int[]

A nice order partition of positive integer n is a nonincreasing ordered
sequence of positive integers that sum to n.  For example, {6,2,1} is a nice
order partition of 9 and {10,3,3,2} is a nice order partition of 18 and {3} is
a nice order partition of 3.

Nice order partitions are ordered based on the following rule:

Partition A is before partition B if and only if there exists a positive
integer x such that
      A1 = B1 and A2 = B2 and . . . and A(x-1) = B(x-1) and Ax > Bx
where Pn is the nth integer in partition P (the i integers in the partition are
numbered 1 to i).

For example the partition {6,3,2,1} is before the partition {6,3,1,1,1} in the
ordered list of nice order partitions of 12.

Implement a class Partitions which contains a method getKthPartition.  The
method inputs two ints, n and k.  The method returns the kth unique nice order
partition of n, using the ordering rule above.  k=1 refers to the first
partition (Start counting at 1, not 0).  The partition is returned as an int[]
of the elements in the partition, where the element with index 0 of the int[]
is the first Integer in the partition, index 1 is the second, etc...

If k is larger than the number of partitions, the method should return an empty
instance of an int[] object.

The method signature is:
public int[] getKthPartition(int n, int k);

n and k satisfy:
  0 < n < 21
  0 < k < 1001

Note:
-The solution must run in under 6 seconds on TopCoder's tester.

Examples:
*If n=5 and k=2, the partitions, in order, are:
  {5}
  {4,1}
  {3,2}
  {3,1,1}
  {2,2,1}
  {2,1,1,1}
  {1,1,1,1,1}
  The 2nd one is {4,1} and the method should return {4,1} as an int[].
*If n=10 and k=7, the method should return {7,1,1,1}
 
Definition
    	
Class:	Partitions
Method:	getKthPartition
Parameters:	int, int
Returns:	int[]
Method signature:	int[] getKthPartition(int param0, int param1)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

class Partitions
{
	private:
		int nparts;
		vector<int> res;
		int part[22];

		void gen(int n, int max, int idx, int k)
		{
			if(n < 0) return;

			if(n == 0)
			{
				nparts++;
				if(nparts == k)
				{
					for (int i = 0; i < idx; ++i)
					{
						res.push_back(part[i]);
					}
				}
				return;
			}
			for (int i = max; i > 0 ; i--)
			{
				part[idx] = i;
				gen(n-i, i, idx+1, k);
			}
		}

	public:
		vector<int> getKthPartition(int n, int k)
		{
			nparts = 0;
			gen(n, n, 0 ,k);
			return res;
		}
};

int main()
{
	Partitions *P = new Partitions;
	//vector<int> kthPartition = P->getKthPartition(8,10);
	//vector<int> kthPartition = P->getKthPartition(1,1);
	//vector<int> kthPartition = P->getKthPartition(1,2);
	//vector<int> kthPartition = P->getKthPartition(19,300);
	vector<int> kthPartition = P->getKthPartition(15,150);

	cout<<"{ ";
	for (int i = 0; i < kthPartition.size(); ++i)
	{
		cout<<kthPartition[i]<<" ";
	}
	cout<<"}";
	return 0;
}