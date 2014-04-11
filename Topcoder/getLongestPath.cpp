/*
Problem Statement
    	
Willy the Worm is crawling through a 5x5 grid.  The squares in the grid are
numbered 0 through 24, from left to right, top to bottom:

0   1   2   3   4
5   6   7   8   9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

Some of the squares contain obstacles.

What is the maximum number of squares Willy can visit before he gets stuck?

Willy travels through the grid as follows:

-He always starts on square 0, going either down or right.
-He can move in four directions: up, down, left, right.
-He cannot travel through:
  (a) an obstacle
  (b) a square he has previously visited
-He moves in a straight line until he reaches a square he can not travel
through or the edge.
-When he cannot move straight, he turns either left or right.
-When he cannot move left, right, or straight, he stops.

Implement a class Obstacle, which contains a method getLongestPath.
getLongestPath is passed an int[] of elements that are the squares which have
obstacles in them, and returns an int that is the maximum number of squares
Willy can visit before he stops.

Examples:
-If the obstacles int[] is {4,12,15,23}, the longest path Willy can travel is:
 0->5->10->11->16->21->22->17->18->19->14->9->8->7->6->1->2->3
 In this path, Willy travels through 18 squares, so the method should return 18.
-If obstacles is {4,10,11,12,14}, the method should return 14

The method signature is:
public int getLongestPath(int[] obstacles);

obstacles is an int[] of elements between 1 and 24, inclusive (0 can not
contain an obstacle).

Note:
-Your algorithm must run in under 6 seconds.
-If Willy cannot move anywhere to start (obstacles on squares 1 and 5), he has
still visited square 0 and the method should return 1.
 
Definition
    	
Class:	Obstacle
Method:	getLongestPath
Parameters:	int[]
Returns:	int
Method signature:	int getLongestPath(int[] param0)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

class Obstacle
{
	private:
		int visited[5][5];
		int best;

		bool isSafe(int row, int col)
		{
			if(row >= 0 && col >= 0 && row < 5 && col < 5)
				if(visited[row][col] == 0)
					return true;
			return false;
		}

		void travel(int row, int col, int dr, int dc, int len)
		{
			if(!isSafe(row,col))
				return;

			visited[row][col] = 1;

			int good = 0;

			if(isSafe(row+dr, col+dc))
			{
				good = 1;
				travel(row+dr, col+dc, dr, dc ,len+1);
			}
			if(good == 0)
			{
				if(dc == 0)
				{
					// try left
          			if (isSafe(row, col + 1)) 
          			{ 
          				good =1;
       					travel(row, col+1, 0, 1, len + 1); 
       				}
       				// try right
          			if (isSafe(row, col - 1)) 
          			{ 
          				good = 1;
       					travel(row, col-1, 0, -1, len + 1); 
       				}
       			} 
       			else if (dr == 0) 
       			{
       				// try left
         			if (isSafe(row + 1, col)) 
         			{ 
         				good =1;
       					travel(row + 1, col, 1, 0, len + 1); 
       				}
      				// try right
          			if (isSafe(row-1, col)) 
          			{ 
          				good = 1;
       					travel(row-1, col, -1, 0, len + 1); 
       				}
       			}
       			if (good == 0) 
       			{
         			// you're screwed
         			if (len > best)
           				best = len;
       			}
     		}
     		visited[row][col] = 0;
     	}

	public:
		int getLongestPath(vector<int> obstacles)
		{
			best = 0;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					visited[i][j] = 0;

			for (int i = 0; i < obstacles.size(); ++i)
				visited[obstacles[i]/5][obstacles[i]%5] = 1;

			travel(0, 0, 1, 0 ,1);
			travel(0, 0, 0, 1 ,1);

			return best;
		}
};

int main()
{
	Obstacle *O = new Obstacle;
	//int arr[] = {4,10,11,14};
	//int arr[] = {5,1,7,8};
	int arr[] = {};
	//int arr[] = {11,22,4,7};
	//int arr[] = {21,9,12,6};
	vector<int> obstacles;
	obstacles.insert(obstacles.begin(),arr,&arr[sizeof(arr)/ sizeof(*arr)]);
	cout<<O->getLongestPath(obstacles)<<"\n";
	return 0;
}