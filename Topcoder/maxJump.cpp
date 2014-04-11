/*
Problem Statement
    	
Class Name: PegJump
Method Name: maxJump
Parameters: int[]
Returns: int

Implement a class PegJump, which contains a method maxJump.  maxJump is passed
an int[] of peg locations (Integers) on a peg jumping game board and returns an
int that is the maximum possible number of successive jumps.

The peg jumping game board is a triangle with 10 holes, numbered 0 through 9:
      0
     /  \
    1 - 2
   /  \  /  \
  3 - 4 - 5
  /  \  /  \  /  \
6 - 7 - 8 - 9
Peg Jumping Game Rules:
1. A peg can only move by jumping another peg.
2. A peg can jump another peg (call the pegs "jumper peg" and "jumpee peg",
respectively) if there is a single line connecting the jumper and jumpee peg
locations and there is a single line of identical direction connecting the
jumpee peg location to an empty location.
3. The jumper peg is removed from its original location, and the original
location is left empty.  
4. The jumper peg ends up in the empty location immediately beyond the jumpee
peg along the line of identical direction as the line connecting the original
jumper hole to jumpee hole.
5. The jumpee peg is removed and its location is left empty.  
6. The game ends when no more pegs can be jumped.

For example, if there is a peg in 0, a peg in 1 and no peg in 3, the 0 peg can
jump the 1 peg.  The peg in 1 is removed, the peg in 0 ends up in 3, and 0 and
1 are left empty.  However, if there are pegs in 0, 1, & 3, and no peg in 4,
the 0 peg cannot jump the 1 peg and end up in 4, because the line from 1 to 4
is not of the same direction as the line from 0 to 1.

The method simulates the game and performs jumps in an order that results in
the maximum possible number of jumps before the game is over, and returns this
maximum number of jumps.

The method signature is:
public int maxJump(int[] pegLoc);

pegLoc is an int[] of size at most 10.  It contains Integers (between 0 and 9,
inclusive) representing initial locations of pegs.  Duplicates are ignored.
For example, if there are initially pegs in locations 1, 2, 3, and 7, pegLoc
may equal {7,2,3,1}.

Note: Any correct solution must execute in fewer than 6 seconds on our tester.
Examples:
-If the initial peg locations are {0,2,4,7}, the sequence that results in the
maximum number of jumps is:
  0 jumps 2, ends in 5.  
  7 jumps 4, ends up in 2.
  5 jumps 2, ends up in 0.
  There are three jumps, and the method should return 3.
-if pegLoc={0,2,3,4,5,8}, the method should return 4.
 
Definition
    	
Class:	PegJump
Method:	maxJump
Parameters:	int[]
Returns:	int
Method signature:	int maxJump(int[] param0)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

int numberOfMoves[10] = {2, 2, 2, 2, 0, 2, 2, 2, 2, 2};

int jumpee1[10] = 	  {1, 3, 4, 1, 0, 2, 3, 4, 4, 8};
int end1[10] =        {3, 6, 7, 0, 0, 0, 1, 2, 1, 7};

int jumpee2[10] = 	  {2, 4, 5, 4, 0, 4, 7, 8, 7, 5 };
int end2[10] =    	  {5, 8, 9, 5, 0, 3, 8, 9, 6, 2 };


class PegJump
{
	private:
        int pegs[10];
        int max;

        void jump(int currJumps)
        {
        	if(currJumps > max)max = currJumps;
        	for (int i = 0; i < 10; ++i)
        	{
        		if(i != 4)
        		{
        			if(pegs[jumpee1[i]] == 1 && pegs[end1[i]] == 0 && pegs[i] == 1)
        			{
        				pegs[jumpee1[i]] = 0;
        				pegs[i] = 0;
        				pegs[end1[i]] = 1;
        				jump(currJumps + 1);
        				pegs[jumpee1[i]] = 1;
        				pegs[i] = 1;
        				pegs[end1[i]] = 0;
        			}
        		}
        	}
        	for (int i = 0; i < 10; ++i)
        	{
        		if(i != 4)
        		{
        			if(pegs[jumpee2[i]] == 1 && pegs[end2[i]] == 0 && pegs[i] == 1)
        			{
        				pegs[jumpee2[i]] = 0;
        				pegs[i] = 0;
        				pegs[end2[i]] = 1;
        				jump(currJumps + 1);
        				pegs[jumpee2[i]] = 1;
        				pegs[i] = 1;
        				pegs[end2[i]] = 0;
        			}
        		}
        	}
        }

	public:
		int maxJump(vector<int> pegLoc)
		{
			max = 0;
			for (int i = 0; i < 10; ++i)
			{
				pegs[i] = 0;
			}
			for (int i = 0; i < pegLoc.size(); ++i)
			{
				pegs[pegLoc[i]] = 1;
			}

			jump(0);

			return max;
		}
};

int main()
{
	PegJump *P = new PegJump;

	//int arr[] = {};
	//int arr[] = {1, 4, 9, 5, 9, 0};
	//int arr[] = {2, 4, 5, 6, 7};
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
	//int arr[] = {0, 1, 2, 3, 5, 6, 7, 9};

	vector<int> pegLoc;
	pegLoc.insert(pegLoc.begin(),arr,&arr[sizeof(arr)/sizeof(*arr)]);
	cout<<P->maxJump(pegLoc)<<"\n";
	return 0;
}